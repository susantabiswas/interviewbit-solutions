/*
    Find no. of ways to reach grid end from left top
    https://www.interviewbit.com/problems/grid-unique-paths/
*/
int Solution::uniquePaths(int m, int n) {
    // (i, j): no. of ways to reach (i, j). Each location can only
    // be reached from top or left side
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    dp[0][0] = 1;
    
    // for 1st column, we can only go down
    for(int i = 0; i < m; i++)
        dp[i][0] = 1;
    // 1st row can be reached only from left side
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;
        
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            // current position can be reached from top and left side
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}
