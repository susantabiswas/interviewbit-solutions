/*
    rotate matrix by 90 degree
    https://www.interviewbit.com/problems/rotate-matrix/
*/

// Solution 1
void Solution::rotate(vector<vector<int> > &mat) {
    int row_s = 0, col_s = 0, 
        row_e = mat.size() - 1, col_e = mat[0].size() - 1;
    
    while(row_s < row_e && col_s < col_e) {
        //cout<<row_s <<" "<<row_e<<" "<<col_s<<" "<<col_e<<endl;
        int n = row_e - row_s + 1;
/*        if(n % 2 != 0)
            n = n / 2;
        else
            n = n / 2 - 1;*/
        for(int i = 0; i < n - 1; i++) {
            int t1 = mat[row_s][col_s + i];
            int t2 = mat[row_s + i][col_e];
            int t3 = mat[row_e][col_e - i];
            int t4 = mat[row_e - i][col_s];
            
            mat[row_s + i][col_e] = t1;
            mat[row_e][col_e - i] = t2;
            mat[row_e - i][col_s] = t3;
            mat[row_s][col_s + i] = t4;
        }
            ++row_s, --row_e, ++col_s, --col_e;
        
    }
}

// Solution 2
void Solution::rotate(vector<vector<int> > &grid) {
    const int N = grid.size();
    int row_start = 0, row_end = N-1, col_start = 0, col_end = N-1;
    
    // since row and cols are N, we can only include one boundary cond
    while(row_start < row_end) {
        // start swapping the outer boundary elements
        int num_elements = col_end - col_start;
        for(int i = 0; i < num_elements; i++) {
            int temp = grid[row_start][col_start + i];
            // 1st row and last column
            swap(temp, grid[row_start + i][col_end]);
        
            // last column and last row
            swap(temp, grid[row_end][col_end - i]);
            
            // last row and 1st column
            swap(temp, grid[row_end - i][col_start]);
             
            // 1st column and 1st row
            swap(temp, grid[row_start][col_start + i]);
        }
        ++row_start, --row_end, ++col_start, --col_end;
    }    
}
