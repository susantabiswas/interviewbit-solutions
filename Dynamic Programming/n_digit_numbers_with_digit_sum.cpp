/*
    No. of numbers whose digit sum equals target
    https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
*/
int Solution::solve(int n, int s) {
    vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
    
    // sum 0 can always be acheived with single digit i.e 0
    for(int i = 0; i < dp.size(); i++)
        dp[i][0] = 1;
    // if no. of digits is zero, no sum can be acheived
    for(int j = 0; j < dp[0].size(); j++)
        dp[0][j] = 0;
    
        
    
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            // if a single digit is there and the sum is <= 9, it can be done
            if(i == 1) {
                if(j <= 9)
                    dp[i][j] = 1;
            }
            else {
                // if sum > 9, we place a number at current position and look
                // if sum - curr_digit is possible with n-1 digits
                for(int k = 0; k <= 9; k++)
                    if(j - k > 0)
                        dp[i][j] = (dp[i][j] % 1000000007 + dp[i-1][j - k] % 1000000007) % 1000000007;
            }
        }
    }
    
    return dp[n][s] % 1000000007;
}
