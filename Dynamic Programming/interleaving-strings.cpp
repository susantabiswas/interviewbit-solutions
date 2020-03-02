/*
    https://www.interviewbit.com/problems/interleaving-strings/
*/
// Using Memoization
// TC: O(MN)
int isInterleaveMem(int i, int j, int k,
                    string& a, string& b, string& c,
                    vector<vector<int>>& dp) {
    // when the entire length of c has been covered
    if(k == 0)
        return true;
    if(dp[i][j] == -1) {
        dp[i][j] = 0;
        // do DFS if either of a or b char matches that of c
        dp[i][j] = (i-1 >= 0) && a[i-1] == c[k-1] && 
                    isInterleaveMem(i-1, j, k-1, a, b, c, dp) ||
                    (j-1 >= 0) && b[j-1] == c[k-1] &&
                    isInterleaveMem(i, j-1, k-1, a, b, c, dp);
    }
    return dp[i][j];
}
              
// Using Tabulation
// TC: O(MN)
int isInterleaveTab(string& a, string& b, string& c,
                    vector<vector<int>> dp) {
    // when length is zero, it is true
    dp[0][0] = 1;
    const int M = a.size(), N = b.size();
    // when b is empty
    for(int i = 1; i <= M; i++)
        dp[i][0] = dp[i-1][0] && a[i-1] == c[i-1];
    // when a is empty
    for(int i = 1; i <= N; i++)
        dp[0][i] = dp[0][i-1] && b[i-1] == c[i-1];
    
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            dp[i][j] = (dp[i-1][j] && a[i-1] == c[i+j-1]) ||
                        (dp[i][j-1] && b[j-1] == c[i+j-1]);
    return dp[M][N];
}

int Solution::isInterleave(string a, string b, string c) {
    const int M = a.size(), N = b.size(), K = c.size();
    // the string lengths should add up to K
    if(M + N != K)
        return 0;
    // dp(i, j): whether till c[i+j-1] interleaves with a[i-1] and b[j-1]
    vector<vector<int>> dp(M+1, vector<int>(N+1, -1));
    //return isInterleaveMem(M, N, K, a, b, c, dp);
    return isInterleaveTab(a, b, c, dp);
}
