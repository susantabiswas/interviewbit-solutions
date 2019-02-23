/*


Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X


*/

// Tc: O(m.n)
void doDFS(vector<vector<char>>& g, int i, int j, vector<vector<bool>>& visited){
    // make visited
    visited[i][j] = true;
    
    // traverse for the 4 directions
    // down
    if(i+1 < g.size() && !visited[i+1][j] && g[i+1][j] == 'O')
        doDFS(g, i+1, j, visited);

    // up
    if(i-1 >= 0 && !visited[i-1][j] && g[i-1][j] == 'O')
        doDFS(g, i-1, j, visited);
    
    // left
    if(j-1 >= 0 && !visited[i][j-1] && g[i][j-1] == 'O')
        doDFS(g, i, j-1, visited);

    // right
    if(j+1 < g[0].size() && !visited[i][j+1] && g[i][j+1] == 'O')
        doDFS(g, i, j+1, visited);

}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // to keep track of visited nodes
    // initially all nodes are unvisited
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    
    const int m = A.size();
    const int n = A[0].size();
    
    // captured 0s are the ones which are isolated from any boundary 0s
    // so do reachability from boundary 0s, all those left are the captured regions
    
    // boundary rows
    for(int i = 0; i<n; i++){
        // top row
        if(A[0][i] == 'O' && !visited[0][i])
            doDFS(A, 0, i, visited);
        // bottom row
        if(A[m-1][i] == 'O' && !visited[m-1][i])
            doDFS(A, m-1, i, visited);
        
    }
    // boundary columns
    for(int i = 0; i<m; i++){
        // top row
        if(A[i][0] == 'O' && !visited[i][0])
            doDFS(A, i, 0, visited);
        // bottom row
        if(A[i][n-1] == 'O' && !visited[i][n-1])
            doDFS(A, i, n-1, visited);
    }
    
    // unvisited Os are the captured Os
    for(int i = 0; i < m; i++){
        for(int j = 0; j< n; j++)
            if(!visited[i][j])
                A[i][j] = 'X';
    }
}
