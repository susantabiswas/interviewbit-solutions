/*
    rotate matrix by 90 degree
    https://www.interviewbit.com/problems/rotate-matrix/
*/

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
