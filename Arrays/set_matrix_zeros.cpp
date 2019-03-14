/*
    Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
    https://www.interviewbit.com/problems/set-matrix-zeros/
*/

void Solution::setZeroes(vector<vector<int> > &mat) {
    const int M = mat.size();
    const int N = mat[0].size();
    
    bool first_row = false;
    bool first_col = false;

    // we use the 1st column and 1st row to store the mark the 
    // ones to set as zero. But for (0,0) it can be ambigous, so
    // bool vars for storing info for 1st row and col
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            //  current element is zero, so we mark its row and column
            if(mat[i][j] == 0) {
                // mark row
                    if(i == 0) 
                        first_row = true;
                    else    
                        mat[i][0] = -1;
                        
                    // mark column
                    if(j == 0)
                        first_col = true;
                    else
                        mat[0][j] = -1;

            }
        }
    }
 
    // now we do one more traversal and set all the rows 
    // and columns marked as zero
    
    // for rows
    for(int i = 1; i < M; i++) {
        if(mat[i][0] == -1) {
            for(int j = 1; j < N; j++) {
                if(mat[i][j] != -1)
                    mat[i][j] = 0;
            }
            // now remove the marker
            mat[i][0] = 0;
        }
    }

    // for columns
    for(int j = 1; j < N; j++) {
        if(mat[0][j] == -1) {
            for(int i = 1; i < M; i++) {
                if(mat[i][j] != -1)
                    mat[i][j] = 0;
            }
            // now remove the marker
            mat[0][j] = 0;
        }
    }
    
    if(first_row) {
        for(int i = 0; i < N; i++) mat[0][i] = 0;
    }
    if(first_col) {
        for(int i = 0; i < M; i++) mat[i][0] = 0;
    }
}
