/*
    https://www.interviewbit.com/problems/chain-of-pairs/
    
    We use LIS here.
    TC: O(N), SC: O(N)
*/
int Solution::solve(vector<vector<int> > &arr) {
    const int N = arr.size();
    int max_len = 1;
    vector<int> dp(N, 1);
    
    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(arr[j][1] < arr[i][0]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                max_len = max(max_len, dp[i]);
            }
    return max_len;
}
