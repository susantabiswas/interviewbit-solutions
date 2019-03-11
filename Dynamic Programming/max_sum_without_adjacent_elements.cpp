/*
    https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
*/

/*
    Each time we can either select current element or leave it.
    If current is selected then we go 2 indices back, since just previous will be
    diagonal or horizontallly adjacent. For current position we try values from row 0 and 1.
    
    If current is not selected we go to previous pos.
*/
int selectNumbers(vector<vector<int>>& arr, int n, vector<int>& dp) {
    if(n <= 0)
        return dp[0] = 0;
    
    if(dp[n] == INT_MIN) {
        // exclude current
        int exclude_curr = selectNumbers(arr, n-1, dp);
        // include current
        int include_curr = max(selectNumbers(arr, n - 2, dp) + arr[0][n-1],
                                selectNumbers(arr, n - 2, dp) + arr[1][n-1]);
        dp[n] = max(include_curr, exclude_curr);
    }
    
    return dp[n];
}

int Solution::adjacent(vector<vector<int> > &arr) {
    vector<int> dp(arr[0].size() + 1, INT_MIN);
    selectNumbers(arr, arr[0].size(), dp);
    
    return dp.back();
}
