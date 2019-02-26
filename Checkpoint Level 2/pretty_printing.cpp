/* 
    https://www.interviewbit.com/problems/prettyprint/
    TC: O(n^2)
*/

vector<vector<int> > Solution::prettyPrint(int n) {
    vector<vector<int>> result(2*n - 1, vector<int>(2*n-1, 0));
    
    int row_s = 0, row_e = 2 * n - 1;
    int col_s = 0, col_e = 2 * n - 1;
    int num = n;
    while(row_s < row_e && col_s < col_e) {
        // top row
        for(int i = col_s; i < col_e; i++)
            result[row_s][i] = num;
        ++row_s;
        
        // right side 
        for(int i = row_s; i < row_e; i++) 
            result[i][col_e - 1] = num;
        --col_e;
        
        // bottom row
        for(int i = col_e - 1; i >= col_s; i--) 
            result[row_e - 1][i] = num;
        --row_e;
        
        // left side
        for(int i = row_e - 1; i >= row_s; i--)
            result[i][col_s] = num;
        ++col_s;
        
        --num;
    }
    
    return result;
}
