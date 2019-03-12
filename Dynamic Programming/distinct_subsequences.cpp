/*
    No. of ways to get target T from source S
    https://www.interviewbit.com/problems/distinct-subsequences/
*/

int Solution::numDistinct(string a, string b) {
    vector<vector<int> > dp(b.size() + 1, vector<int>(a.size() + 1, 0));
    
    // when target T has zero size, then it can be formed for any 
    // length of S in one way
    for(int i = 0; i <= a.size(); i++)
        dp[0][i] = 1;
        
    for(int i = 1; i <= b.size(); i++) {
        for(int j = 1; j <= a.size(); j++) {
            // if chars are same, then either we can include current(dp[i-1][j-1])
            // or exclude current(dp[i][j-1]) of S
            if(a[j - 1] == b[i - 1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
                // exclude current of S
                dp[i][j] = dp[i][j-1];
        }
    }
    
    return dp.back().back();
}
