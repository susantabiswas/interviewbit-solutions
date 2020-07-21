/*
    https://www.interviewbit.com/problems/increasing-path-in-matrix/
    
    For each position we take the max path length that can be travelled either
    from its left or top. Also make sure that the paths till left and top
    also are reachable from source.
    TC: O(MN)
*/
int Solution::solve(vector<vector<int> > &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));
    
    dp[0][0] = 1;
    // 1st row
    for(int i = 1; i < N; i++)
        if(dp[0][i-1])
            dp[0][i] = grid[0][i-1] < grid[0][i] ? dp[0][i-1] + 1 : 0;
    // 1st col
    for(int i = 1; i < M; i++)
        if(dp[i-1][0])
            dp[i][0] = grid[i-1][0] < grid[i][0] ? dp[i-1][0] + 1 : 0;
    
    for(int i = 1; i < M; i++)
        for(int j = 1; j < N; j++) {
            int top = 0, left = 0;
            // check if a path is possible till its top and 
            // from top to current
            if(dp[i-1][j] && grid[i-1][j] < grid[i][j])
                top = 1 + dp[i-1][j];
            // check if there is a path till its left and 
            // from left to current
            if(dp[i][j-1] && grid[i][j-1] < grid[i][j])
                left = 1 + dp[i][j-1];
            dp[i][j] = max(top, left);
        }
    return dp[M-1][N-1] == 0 ? -1 : dp[M-1][N-1];
}
