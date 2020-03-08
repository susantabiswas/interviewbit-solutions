/*
    https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
    
    TC: O(MN) + O(M * (NlognN + N))
    => O(MN) + O(MN) + O(MNlogN)
    => O(MNlogN)
*/
int Solution::solve(vector<vector<int> > &grid) {
    if(grid.empty())
        return 0;
        
    int max_area = 0;
    const int M = grid.size(), N = grid[0].size();
    // dp(i, j): No. of consecutive 1s in jth column and ith row
    vector<vector<int>> dp(M, vector<int>(N, 0));
    
    // Find the column wise consecutive 1s
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(grid[i][j])
                dp[i][j] = 1 + dp[max(i-1, 0)][j];
                
    // Now since we already have the consecutive column 1s sum, we can arrange the 
    // columns on row basis. The thing is we don't know which columns to move
    // because say for ith row, we have height lesser than that of i+1th row, but
    // arranging the columns such that it ensures consecutive 1s in ith row can give more area
    // So we sort the rows in non-increasing order and also calculate the max histogram area till there.
    /*
        1 0 0 1         1 1 0 0
        2 0 0 2 ==>     2 2 0 0
        3 0 1 0         3 0 0 1, 
        so knowing for which row to arrange the columns is difficult,
        So we do it row basis, since we already have the consecutive 1s for each column for that row. 
    */
    for(int i = 0; i < M; i++) {
        // arrange in non-increasing order
        sort(begin(dp[i]), end(dp[i]), greater<>());
        // find the max histogram area
        for(int j = 0; j < N; j++) {
            // current column height is blocked by its right side since that is smaller, so
            // its height is valid only between till there
            int curr_area = dp[i][j] * (j + 1);
            max_area = max(max_area, curr_area);
        }
    }
    
    return max_area;
}
