/*
    Find the min sum path in matrix 
    https://www.interviewbit.com/problems/min-sum-path-in-matrix/

*/

/*
    For each (i, j), we can reach there either from its left or from top.
    So for each location we find the min path value from its left and top and
    add the current value to that min path.
    For the top row, we can reach the elements only by going right.
    For 1st column we can only reach by going down
    
    TC: O(n^2)
*/
int findMinPathSum(vector<vector<int>>& mat, int i, int j, 
                    vector<vector<int>>& dp) {
    if(i == 0 && j == 0)
        return dp[i][j] = mat[i][j];
    // top row   
    if(i == 0 && j > 0)
        return dp[i][j] = findMinPathSum(mat, i, j - 1, dp) + mat[i][j];
    // 1st column
    if(i > 0 && j == 0)
        return dp[i][j] = findMinPathSum(mat, i - 1, j, dp) + mat[i][j];
        
    if(dp[i][j] == 0) {
        dp[i][j] = mat[i][j] + min(findMinPathSum(mat, i - 1, j, dp), // from top
                                    findMinPathSum(mat, i, j - 1, dp)); // from left
    }
    
    return dp[i][j];
}

int Solution::minPathSum(vector<vector<int> > &mat) {
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
    
    findMinPathSum(mat, mat.size() - 1, mat[0].size() - 1, dp);

    return dp[mat.size() - 1][mat[0].size() - 1];
}
