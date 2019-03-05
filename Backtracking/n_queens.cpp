/*  
    N queens problem.
    https://www.interviewbit.com/problems/nqueens/
*/

// check if placement at current position is possible
bool isPositionSafe(vector<string> sol, int row, int col) {
    const int n = sol.size();
    
    // check row
    for(int i = 0; i < n; i++)
        if(sol[i][col] == 'Q')
            return false;
     
    // check column
    for(int i = 0; i < n; i++)
        if(sol[row][i] == 'Q')
            return false;
            
    // check diagonals
    int i, j;
    //left upper
    for(i = row, j = col; i >= 0 && j >= 0; j--,i--)
        if(sol[i][j] == 'Q')
            return false;
   
    //upwards right
    for(i= row, j = col; i >= 0 && j < n; j++,i--)
        if(sol[i][j] == 'Q')
            return false;
    //downwards left
    for(i = row, j = col; i < n && j >= 0; j--,i++)
        if(sol[i][j] == 'Q')
            return false;
     //downwards right
    for(i = row, j = col; i < n && j < n; j++,i++)
        if(sol[i][j] == 'Q')
            return false;
    return true;
}

void placeNQueens(int row, int n, vector<string> sol,
                        vector< vector<string> >& result) {
    // if all the queens have been placed
    if(row == n) {
        result.emplace_back(sol);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(isPositionSafe(sol, row, i)) {
            // place the queen
            sol[row][i] = 'Q';
            placeNQueens(row + 1, n, sol, result);
            // revert back change
            sol[row][i] = '.';
        }
    }
}
                        
vector<vector<string> > Solution::solveNQueens(int n) {
    vector< vector<string> > result;
    int c = n;
    string str;
    while(c--)
        str += '.';
        
    vector<string> sol(n, str);
    
    int row = 0;
    placeNQueens(row, n, sol, result);
    
    return result;
}
