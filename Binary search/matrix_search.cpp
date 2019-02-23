/*
    Search a target in sorted matrix
    https://www.interviewbit.com/problems/matrix-search/

    TC: O(N + M)
*/
int Solution::searchMatrix(vector<vector<int> > &arr, int val) {
    int row = arr.size() - 1;
    int col = 0;
    const int M = arr[0].size();    // no. of columns
    
    // We start with an element such that we can prune our search
    // so we select row with largest values and col with smallest values
    while(row >= 0 && col < M) {
        // target found
        if(arr[row][col] == val) {
            return 1;
        }    
        else if(arr[row][col] > val) {
            --row;
        }
        else {
            ++col;
        }
    }
    
    return 0;
}
