/*
    https://www.interviewbit.com/problems/word-search-board/
    TC: O((mn)^2)
*/

bool DFS(vector<string>& grid, int i, int j, int curr, string& target) {
    // boundary checking
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
        // if the current char doesn't match target
        if(target[curr] != grid[i][j])
            return false;
        // if target is found    
        if(curr == target.size()-1)
            return target[curr] == grid[i][j];
        // dfs in 4 directions
        if(DFS(grid, i, j-1, curr+1, target) ||
            DFS(grid, i-1, j, curr+1, target) ||
            DFS(grid, i, j+1, curr+1, target) ||
            DFS(grid, i+1, j, curr+1, target))
            return true;
    }
    return false;
}

int Solution::exist(vector<string> &grid, string target) {
    // try searching from all the positions
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++)
            if(DFS(grid, i, j, 0, target))
                return true;
    }
    return false;
}
