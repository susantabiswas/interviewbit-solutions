/*
    Spiral order printing of numbers from 1 to n^2
    https://www.interviewbit.com/problems/spiral-order-matrix-ii/
    TC: O(n^2)
*/

vector<vector<int> > Solution::generateMatrix(int n) {
    int row_s = 0, row_e = n - 1;
    int col_s = 0, col_e = n - 1;
    
    vector<vector<int>> result(n, vector<int>(n, 0));
    int c = 1;
    while(row_s <= row_e && col_s <= col_e) {
        // top row
        for(int i = col_s; i <= col_e; i++)
            result[row_s][i] = c++;
        ++row_s;
        
        // right side
        for(int i = row_s; i <= row_e; i++)
            result[i][col_e] = c++;
        --col_e;
        
        // bottom row
        for(int i= col_e; i >= col_s; i--)
            result[row_e][i] = c++;
        --row_e;
        
        // left side
        for(int i = row_e; i >= row_s; i--)
            result[i][col_s] = c++;
        ++col_s;
    }
    
    return result;
}
