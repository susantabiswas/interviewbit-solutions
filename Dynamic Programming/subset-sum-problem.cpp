/*
    https://www.interviewbit.com/problems/subset-sum-problem/
    
    TC: O(NB)
*/
int Solution::solve(vector<int> &nums, int B) {
    vector<bool> dp(B + 1, false);
    dp[0] = true;
    for(const int& num: nums)
        // Check from back side to avoid accounting for the
        // same number multiple times
        for(int i = B; i >= 1 && num <= i; i--)
            dp[i] = dp[i] || dp[i - num];
    return dp.back();
}
