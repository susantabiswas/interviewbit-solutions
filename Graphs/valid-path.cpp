/*
    https://www.interviewbit.com/problems/valid-path/
*/

// DFS
// O(XY)
bool DFS(vector<vector<int>>& grid, int i, int j) {
    /// boundary check or unreachable
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j])
        return false;
    // destination reached
    if(i == grid.size()-1 && j == grid[0].size()-1)
        return true;
    
    // make current unreachable
    grid[i][j] = 0;
    // move in 8 directions
    if(DFS(grid, i, j-1) || DFS(grid, i-1, j-1) ||
        DFS(grid, i-1, j) || DFS(grid, i-1, j+1) ||
        DFS(grid, i, j+1) || DFS(grid, i+1, j+1) ||
        DFS(grid, i+1, j) || DFS(grid, i+1, j-1))
            return true;
    return false;
}

// TC: O(XYN) + O(XY), XY= size of grid, N: no. of circles
string Solution::solve(int x, int y, int n, int r, vector<int> &X, vector<int> &Y) {
    // matrix of grid, 0 is blocked cell and 1 is accessible cell
    vector<vector<int>> grid(x+1, vector<int>(y+1, 1));
    // if a cell is under a circle, it is unreachable
    for(int j = 0; j < grid.size(); j++)
        for(int k = 0; k < grid[0].size(); k++)
            for(int i = 0; i < X.size(); i++) {
                if(sqrt(pow(X[i] - j, 2) + pow(Y[i] - k, 2)) <= r)
                    grid[j][k] = 0;
            }
                
    // DFS from the starting point
    return DFS(grid, 0, 0) ? "YES" : "NO";
}
