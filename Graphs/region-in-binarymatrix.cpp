/*
    https://www.interviewbit.com/problems/region-in-binarymatrix/
    
    We do DFS to traverse the connected regions.
    TC: O(MN)
*/
void dfs(int i, int j, vector<vector<int>>& grid,
    long long& num_nodes) {
    // check boundary and if visited
    if(i < 0 || i >= grid.size() ||
      j < 0 || j >= grid[0].size() ||
      grid[i][j] == 0)
        return;
    // make it visited
    grid[i][j] = 0;
    ++num_nodes;
    // traverse all the neighbors
    dfs(i+1, j, grid, num_nodes);
    dfs(i-1, j, grid, num_nodes);
    dfs(i, j-1, grid, num_nodes);
    dfs(i, j+1, grid, num_nodes);
    dfs(i+1, j+1, grid, num_nodes);
    dfs(i+1, j-1, grid, num_nodes);
    dfs(i-1, j+1, grid, num_nodes);
    dfs(i-1, j-1, grid, num_nodes);
}

int Solution::solve(vector<vector<int> > &grid) {
    long long max_nodes = 0, num_nodes = 0;
    
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            if(grid[i][j]) {
                num_nodes = 0;
                dfs(i, j, grid, num_nodes);
                max_nodes = max(max_nodes, num_nodes);
            }
                
    return max_nodes;
}
