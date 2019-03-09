/*
    Find no. of ways of climbing stairs
    https://www.interviewbit.com/problems/stairs/
*/

// Each time we can take either 1 or 2 steps
int findWaysToClimb(int n, vector<int>& dp) {
    // when all the stairs have been climbed
    if(n == 0)
        return 1;
    if(n < 1)
        return 0;
        
    if(dp[n] == 0) {
        dp[n] = findWaysToClimb(n - 1, dp) + 
                findWaysToClimb(n - 2, dp);
    }
    
    return dp[n];
}

int Solution::climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    
    findWaysToClimb(n, dp);
    return dp[n];
}
