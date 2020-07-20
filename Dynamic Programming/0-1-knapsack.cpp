/*
    https://www.interviewbit.com/problems/0-1-knapsack/
    
    TC: O(NC)
*/

int Solution::solve(vector<int> &values, vector<int> &weights, int C) {
    const int N = values.size();
    vector<vector<int>> dp(N, vector<int>(C + 1, 0));
    
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= C; j++) {
            int with = values[i] + (i == 0 ? 0 : dp[i-1][j - weights[i]]);
            int without = i == 0 ? 0 : dp[i-1][j];
            // current weight is more than capacity:
            // Don't use current, use till previous
            if(weights[i] > j)
                dp[i][j] = without;
            // Current weight <= capacity:
            // Max of with ot without current
            else
                dp[i][j] = max(with, without);
        }
    return dp[N-1][C];
}
