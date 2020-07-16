/*
    https://www.interviewbit.com/problems/maximum-sum-combinations/
    
    TC: O(MlogM + NlogN + ClogC)
*/

// Custom hash for unordered set of pair
struct PairHash {
    size_t operator()(const pair<int, int>& a) const {
        return hash<int>()(a.first) * 1021 ^ hash<int>()(a.second) * 329;
    }    
};

vector<int> result;
    struct SumCmb {
    int sum = 0, a_idx = 0, b_idx = 0;    
    bool operator<(SumCmb &val) const {
        return sum <= val.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    if(A.empty() || B.empty())
        return {};
        
    // Sort the arrays so that at each point we are sure about the largest element
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    const int M = A.size(), N = B.size();
    // max heap of cmb sum 
    priority_queue<SumCmb, vector<SumCmb>, less<>> max_heap;
    max_heap.emplace(SumCmb{A[M-1] + B[N-1], M-1, N-1});
    
    // for keeping track of same idx pair, diff cmb can ultimately 
    // lead to the same cmb idx pair when pushing the elements with idx-1
    unordered_set<pair<int, int>, PairHash> visited;
    visited.emplace(make_pair(M-1, N-1));
    
    while(!max_heap.empty() && C--) {
        auto curr = max_heap.top();
        max_heap.pop();
        result.emplace_back(curr.sum);
        
        // Add a_idx-1 + b_idx and a_idx + b_idx-1
        if(curr.a_idx - 1 >= 0 && !visited.count({curr.a_idx - 1, curr.b_idx})) {
            max_heap.emplace(SumCmb{A[curr.a_idx - 1] + B[curr.b_idx], 
                                curr.a_idx - 1, curr.b_idx });
            visited.emplace(curr.a_idx - 1, curr.b_idx);
        }
        if(curr.b_idx - 1 >= 0 && !visited.count({curr.a_idx, curr.b_idx - 1})) {
            max_heap.emplace(SumCmb{A[curr.a_idx] + B[curr.b_idx - 1], 
                                curr.a_idx, curr.b_idx - 1 });
            visited.emplace(curr.a_idx, curr.b_idx - 1);
        }
    }
    return result;
}
