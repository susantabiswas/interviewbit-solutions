/*  
  Fill the vacant positions of partially filled Sudoku Box
  https://www.interviewbit.com/problems/sudoku/
*/

// finds unassigned position
bool findVacantPosition(vector<vector<char>>& mat, int& row, int& col) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            if(mat[i][j] == '.') {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// checks if the current assignment is valid
bool isSafe(vector<vector<char>>& mat, int row, int col) {
    char curr_digit = mat[row][col];
    // check row
    for(int i = 0; i < mat.size(); i++)
        if(mat[i][col] == curr_digit)
            return false;
    // check col
    for(int i = 0; i < mat[0].size(); i++)
        if(mat[row][i] == curr_digit)
            return false;
            
    // check grid
    int grid_row_start = 3 * (row / 3);
    int grid_col_start = 3 * (col / 3);
    for(int i = grid_row_start; i < grid_row_start + 3; i++) {
        for(int j = grid_col_start; j < grid_col_start + 3; j++) {
            if(mat[i][j] == curr_digit)
                return false;
        }
    }
    
    return true;
}

bool fillSudoku(vector<vector<char>>& mat, int row, int col) {
    // first check if the sudoku is filled or not
    if(findVacantPosition(mat, row, col) == false)
        return true;
        
    // now try filling the vacant position with 1-9 
    for(int i = 1; i <= 9; i++) {
        mat[row][col] = i + '0';
        // check if the current assignment is valid or not
        if(isSafe(mat, row, col))
            if(fillSudoku(mat, row, col))
                return true;
        mat[row][col] = '.';
    }
    
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &mat) {
     int row = 0, col = 0;
     fillSudoku(mat, row, col);
}
