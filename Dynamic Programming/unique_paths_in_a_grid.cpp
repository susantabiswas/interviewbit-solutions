/*
    Find the ways to reach bottom right of matrix from top left
    https://www.interviewbit.com/problems/unique-paths-in-a-grid/
*/

/*
    For each location we can get there either from its left or top and
    when that position is vacant.
*/
int waysOfReaching(vector<vector<int> > &mat, int i, int j, 
                    vector<vector<int> > &dp) {
    if(i < 0 || j < 0)
        return 0;
    // base case: starting position
    if(i == 0 && j == 0 && mat[i][j] == 0)
        return dp[i][j] = 1;
        
    // top row
    if(i == 0 && j > 1)
        return dp[i][j] = mat[i][j] == 0 ? waysOfReaching(mat, i, j - 1, dp) : 0;
    // 1st column
    if(i > 1 && j == 0)
        return dp[i][j] = mat[i][j] == 0 ? waysOfReaching(mat, i - 1, j, dp) : 0;
        
        
    if(dp[i][j] == -1) {
        // when the current position is vacant
        if(mat[i][j] == 0) {
            dp[i][j] =  waysOfReaching(mat, i - 1, j, dp) +
                        waysOfReaching(mat, i, j - 1, dp);
        } 
        else 
            dp[i][j] = 0;
    }
    return dp[i][j];
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &mat) {
    const int N = mat.size(), M = mat[0].size();
    vector<vector<int>> dp(N, vector<int>(M, -1));

    waysOfReaching(mat, mat.size() - 1, mat[0].size() - 1, dp);
    return dp[N-1][M-1];
}
