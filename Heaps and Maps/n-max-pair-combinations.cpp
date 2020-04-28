/*
    https://www.interviewbit.com/problems/n-max-pair-combinations/
    
    We sort the array so that we know for sure where to start from to get 
    the largest pair. We use a max heap to keep track of largest sum.
    We also add the index pair alongside each sum, every time the largest
    sum is popped from heap, we push the next potential largest elements
    formed by the current largest sum pair numbers.
    A[a_idx-1] + B[b_idx], 
    A[a_idx] + B[b_idx]
    
    To ensure that the same set of indices dont get pushed, a set is used.
*/
// TC: O(NlogN)
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // to make sure that only unique elemnet pairs get inserted
    set<pair<int, int>> index_pair;
    
    priority_queue<pair<int, pair<int,int>>,
            vector<pair<int, pair<int, int>>>, less<>> max_heap;
    // add the largest sum pair
    max_heap.emplace(make_pair(A.back() + B.back(),
                    make_pair(A.size()-1, B.size()-1))
                );
    // add the index pair
    index_pair.emplace(make_pair(A.size()-1, B.size()-1));
    int n = A.size();
    vector<int> result;
    
    while(n--) {
        auto element = max_heap.top();
        max_heap.pop();
        int a_idx = element.second.first;
        int b_idx = element.second.second;
        
        // add the next 2 largest elements: A[a_idx-1] + B[b_idx], 
        // A[a_idx] + B[b_idx], since it is pushed to a max heap
        // next largest element will be decided automatically,
        // then we use that index to use that index to get the next two largest
        
        // add the number pair, if already not present
        if(index_pair.count(make_pair(a_idx, b_idx-1)) == 0) {
            auto next_largest = make_pair(A[a_idx] + B[b_idx-1],
                    make_pair(a_idx, b_idx-1));
            max_heap.emplace(next_largest);
            index_pair.emplace(make_pair(a_idx, b_idx-1));
        }
        
        // add the number pair, if already not present
        if(index_pair.count(make_pair(a_idx-1, b_idx)) == 0) {
            auto next_largest = make_pair(A[a_idx-1] + B[b_idx],
                    make_pair(a_idx-1, b_idx));
            max_heap.emplace(next_largest);
            index_pair.emplace(make_pair(a_idx-1, b_idx));
        }
        
        result.emplace_back(element.first);
    }
    return result;
}
