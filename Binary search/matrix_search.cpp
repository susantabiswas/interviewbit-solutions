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


// Solution 2
// Using binary search
// TC: O(long(MN))
int matrixBSearch(vector<vector<int> > &grid, int target) {
    const int M = grid.size(), N = grid[0].size();
    int low = 0, high = M * N - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / N, c = mid % N;
        
        if(grid[r][c] == target)
            return 1;
        else if(grid[r][c] < target)
            ++low;
        else
            --high;
    }
    return 0;
}
