/*
    Find the longest increasing subsequence length
    https://www.interviewbit.com/problems/longest-increasing-subsequence/

    TC: O(n^2)
*/

int Solution::lis(const vector<int> &arr) {
    // ith entry in LIS stores the max LIS till that point
    vector<int> lis(arr.size(), 1);
    int max_len = 1;
    
    for(int i = 1; i < arr.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
            max_len = max(max_len, lis[i]);
        }
    }
    return max_len;
}
