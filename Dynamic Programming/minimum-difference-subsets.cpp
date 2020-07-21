/*
    https://www.interviewbit.com/problems/minimum-difference-subsets/
*/

#include <numeric>
int Solution::solve(vector<int> &nums) {
    long long total = accumulate(nums.begin(), nums.end(), 0);
    int min_diff = total;
    vector<bool> dp(total/2 + 1, false);
    // 0 sum can always be achieved
    dp[0] = true;
    
    for(const int& num: nums)
        for(int sum = total/2 + 1; sum >= 1; sum--) {
            if(num <= sum)
                dp[sum] = dp[sum] || dp[sum - num];
            if(dp[sum]) {
                int subset_diff = abs(2*sum - total);
                min_diff = min(min_diff, subset_diff);
            }
        }
    
    return min_diff;
}
