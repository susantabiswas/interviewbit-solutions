/*
    https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/
    TC: O(MN)
    SC: (N)
*/
int Solution::solve(vector<vector<int> > &grid) {
    const int M = grid.size(), N = grid[0].size();
    int max_len = 0;
    vector<int> prev(N), curr(N, 0);
    
    // Set the previous state with the first row of grid
    for(int i = 0; i < N; i++) {
        prev[i] = grid[0][i];
        max_len = max(max_len, prev[i]);
    }
    for(int i = 1; i < M; i++) {
        for(int j = 0; j < N; j++) {
            // Initialize the max sq ending at current pos.
            curr.emplace_back(grid[i][j]);
            if(grid[i][j]) {
                curr[j] = 1 + min({curr[j-1], 
                                    prev[j],
                                    prev[j-1]});
            }
            max_len = max(max_len, curr[j]);
        }
        prev = move(curr);
    }
    return max_len * max_len;
}
