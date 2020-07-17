/*
  https://www.interviewbit.com/problems/subarray-with-equal-occurences/
*/

// solution 1: TC: O(N), SC: O(N)
// Idea is to use the diff of B and C freq to look for subarrays where
// the intermediate values cancel each 
int sol1(vector<int>& A, int B, int C) {
    const int N = A.size();
    // (diff between freq of b and c, number of such diffs in array)
    unordered_map<int, int> pos;
    int subarrays = 0, b_freq = 0, c_freq = 0;
    
    // Empty subarray sum
    pos[0] = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] == B)
            ++b_freq;
        else if(A[i] == C)
            ++c_freq;
            
        int diff = c_freq - b_freq;
        // check if the same diff was seen before or not
        // if the same diff was seen, means all the B and C from
        // that point till current index cancel each other and hence
        // have the same frequency
        
        // current pos can create subarrays from all previous positions with same diff
        // For any previous pos 'j' with same sum, subarray is created with [j+1, i]
        // since only after jth index there were elements which cancelled each other
        if(pos.count(diff)) 
            subarrays += pos[diff];
        pos[diff] += 1;
    }
    return subarrays;
}


// Solution 2: TC: O(n^2), SC: O(N)
int sol2(vector<int> &A, int B, int C) {
    const int N = A.size();
    // (B freq, C freq)
    vector<pair<int, int>> freq(N, make_pair(0, 0));
    int subarrays = 0;
    
    // find tthe frequency of B and C till ith index    
    int b_freq = 0, c_freq = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == B) 
            ++b_freq;
        else if(A[i] == C)
            ++c_freq;
        freq[i].first = b_freq;
        freq[i].second = c_freq;
    }
    
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++) {
            // for the given subarray check if the frequency matches
            int b_count = i == 0 ? freq[j].first : freq[j].first - freq[i-1].first;
            int c_count = i == 0 ? freq[j].second : freq[j].second - freq[i-1].second;
            if(b_count == c_count)
                ++subarrays;
        }
            
    return subarrays;
}

int Solution::solve(vector<int> &A, int B, int C) {
    // return sol2(A, B, C);
    return sol1(A, B, C);
}
