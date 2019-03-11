/*
    Coin game
    https://www.interviewbit.com/problems/coins-in-a-line/
*/

int findMaxValue(vector<int>& arr, int i, int j, vector<vector<int> >& dp, bool myturn) {
    // base case
    if(i > j)
        return 0;

    if(dp[i][j] == -1) {
        // I will try to maximize my value
        if(myturn) 
            dp[i][j] = max(arr[i] + findMaxValue(arr, i+1, j, dp, false),
                        arr[j] + findMaxValue(arr, i, j-1, dp, false));
        else
            // opponent will try to give me minimum value possible to select from
            dp[i][j] = min(findMaxValue(arr, i+1, j, dp, true), findMaxValue(arr, i, j-1, dp, true));
    }
    return dp[i][j];
        
}

int Solution::maxcoin(vector<int> &arr) {
    const int N = arr.size();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    
    findMaxValue(arr, 0, N-1, dp, true);
    return dp[0][N-1];
}
