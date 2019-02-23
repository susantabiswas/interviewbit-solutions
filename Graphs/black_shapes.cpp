/* 

Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X

Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX

is just one single connected black shape.
 */

//TC:O(n), n: vector length
void DFS(vector<string>& grid, int i, int j, vector<vector<bool>>& visited){
    // make the current tile visited
    visited[i][j] = true;
    
    // visit adjacent tiles
    if(i+1 < grid.size() && grid[i][j] != 'O' && !visited[i+1][j])
        DFS(grid, i+1, j, visited);
    if(i-1 >= 0 &&  grid[i][j] != 'O' && !visited[i-1][j])
        DFS(grid, i-1, j, visited);
    if(j+1 < grid[0].size() &&  grid[i][j] != 'O' && !visited[i][j+1])
        DFS(grid, i, j+1, visited);
    if(j-1 >= 0 &&  grid[i][j] != 'O' && !visited[i][j-1])
        DFS(grid, i, j-1, visited);
}

int Solution::black(vector<string> &A) {
    const int n = A.size();
    const int m = A[0].size();
    
    int regions = 0;
    
    // for keeping track of visited nodes
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // if the block is unvisited and black
            if(!visited[i][j] && A[i][j] == 'X'){
                DFS(A, i, j, visited);
                ++regions;
            }
        }
    }
    
    return regions;
}
