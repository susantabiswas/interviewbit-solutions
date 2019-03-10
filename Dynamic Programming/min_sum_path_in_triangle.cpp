/*
    Min sum path in triangle
    https://www.interviewbit.com/problems/min-sum-path-in-triangle/ 
*/

int Solution::minimumTotal(vector<vector<int> > &arr) {
    vector<int> last(arr.back().size(), 0);
    
    // store the last row values
    for(int i = 0; i < arr.back().size(); i++)
        last[i] += arr.back()[i];
    
    // we start with the last row and work our way up.
    // Each time we select the smallest of the two adjacent
    for(int i = arr.size() - 2; i >= 0; i--) {
        for(int j = 0; j < arr[i].size(); j++) {
            last[j] = min(last[j], last[j+1]) + arr[i][j];
        }
    }
    return last[0];
}
