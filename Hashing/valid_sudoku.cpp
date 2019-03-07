/*
    Check if given sudoku is valid 
    https://www.interviewbit.com/problems/valid-sudoku/
*/

// checks the sudoku constraints
bool isSafe(const vector<string>& mat, int row, int col) {
    const int N = mat.size();
    const int M = mat[0].size();
    char digit = mat[row][col];
    
    // check row
    for(int i = 0; i < N; i++)
        if(mat[i][col] == digit && i != row)
            return false;
    
    // check column
    for(int i = 0; i < M; i++)
        if(mat[row][i] == digit && i != col)
            return false;
            
    // check grid
    int grid_row_start = 3 * (row / 3);
    int grid_col_start = 3 * (col / 3);
    for(int i = grid_row_start; i < grid_row_start + 3; i++)
        for(int j = grid_col_start; j < grid_col_start + 3; j++)
            if(mat[i][j] == digit && i != row && j != col)
                return false;
    
    return true;
}

int Solution::isValidSudoku(const vector<string> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            // if the position is not vacant
            if(mat[i][j] != '.') {
                if(isSafe(mat, i, j) == false)
                    return 0;
            }
        }
    }
    
    return 1;
}
