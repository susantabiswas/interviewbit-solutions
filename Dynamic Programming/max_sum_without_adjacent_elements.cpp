/*
    https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
    
    The idea is to track the max sum that can be achieved till ith element.
    Since the previous elemenet if added in the sum, then current can't be added,
    so we track two states:
    1. Sum without current number
    2. Sum with current number
*/
// TC: O(N)
int Solution::adjacent(vector<vector<int> > &arr) {
    int with_curr = 0, without_curr = 0,
        with_curr_prev = 0, without_curr_prev = 0;
        
    for(int i = 0; i < arr[0].size(); i++) {
        // max sum if the current number is added
        with_curr = max(arr[0][i], arr[1][i]) + without_curr_prev;
        // max sum if the current number is not added,
        // it can either be the max sum till the last element when it
        // was added or not added
        without_curr = max(without_curr, with_curr_prev);
        // update the previous state values    
        with_curr_prev = with_curr, without_curr_prev = without_curr;
    }
    return max(with_curr, without_curr);
}


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
