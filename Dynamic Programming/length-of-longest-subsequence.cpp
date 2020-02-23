/*
    https://www.interviewbit.com/problems/length-of-longest-subsequence/

    find the LIS from left to right and save the result, do
    the same from right to left (LDS) and and while doing the
    backward pass, track the max subsequence which is increasing and decreasing
    
*/
// TC: O(N^2)
// SC: O(N)
int Solution::longestSubsequenceLength(const vector<int> &arr) {
    if(arr.size() == 0)
        return 0;
    const int N = arr.size();
    // dp(i): LIS when ith element isthe last element
    vector<int> lis(N, 1);
    // forward pass to get the increasing subsequence
    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
                
    // backward pass to get longest decreasing subsequence
    vector<int> lds(N, 1);
    // max length of req. sequence
    int max_len = 1;
    for(int i = N-1; i >= 0; i--) {
        for(int j = N-1; j > i; j--) {
            if(arr[j] < arr[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
        max_len = max(max_len, lds[i] + lis[i] - 1);
    }
    return max_len;
}
