/*
    https://www.interviewbit.com/problems/maximum-path-in-triangle/
*/

int Solution::solve(vector<vector<int> > &arr) {
    for(int i = arr.size() - 2; i >= 0; i--) 
        for(int j = 0; j < arr[i+1].size(); j++)
            arr[i][j] = arr[i][j] + max(arr[i+1][j], arr[i+1][j+1]);
    return arr[0][0];
}
