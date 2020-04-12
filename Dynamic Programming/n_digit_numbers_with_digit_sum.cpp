/*
    No. of numbers whose digit sum equals target
    https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
*/

// Using memoization
// TC: O(NS)
int memoize(int n, int sum, vector<vector<int>>& dp) {
    // when no more digits can be used
    if(n == 0)
        return dp[n][sum] = (sum == 0);
    // when no sum is left
    if(sum == 0)
        return dp[n][sum] = (n == 0);
    
    if(dp[n][sum] == -1) {
        dp[n][sum] = 0;
        // try putting [0-9] digits at current position
        for(int i = 0; i <= 9; i++) 
            if(i <= sum) {
                dp[n][sum] += memoize(n-1, sum - i, dp);
                dp[n][sum] %= 1000000007;
            }
    }
    return dp[n][sum] % 1000000007;
}

// Using tabular method
// TC: O(NS)
int tabular(int n, int sum, vector<vector<int>>& dp) {
    // if there are no digits, no sum can be formed
    for(int i = 0; i <= sum; i++)
        dp[0][i] = 0;
        
    // using 1 digit only [0-9] can be formed
    for(int i = 0; i <= min(9, sum); i++)
        dp[1][i] = 1;
      
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            for(int k = 0; k <= 9; k++) {
                // only when current digit - sum > 0
                // some sum should be left so that initial digits
                // can account for something other than 0
                // eg: S=3, N=2, 
                // _3, sum_rem = 0, now n = 1 and sum = 0 is true
                // but that means 03 which is not valid, so only allow sum > 0 
                if(k < j) {
                    dp[i][j] += dp[i-1][j - k];
                    dp[i][j] %= 1000000007; 
                }
            }
        }
    }
    
    return dp[n][sum] % 1000000007;
}

int Solution::solve(int N, int S) {
    // dp[i][j]: no. of ways to get j sum with i no. if digits
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));
    //return memoize(N, S, dp);
    return tabular(N, S, dp);
}


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
