/*
    https://www.interviewbit.com/problems/flip-array/
    TC: O(NW)
    
    Idea is to find the min target based on set paritioning. Then find the
    min number of numbers required to make up the mminimum set out of two.
    if n_P < n_N, then we can simply make n_P as the set carrying the negative 
    numbers. So we pick the min num element set.
*/
#include<bits/stdc++.h>

// Finds the min number of elements required to fill the knapsack
// TC: O(NW)
int findMinKnapsackElements(int min_wt, const vector<int>& nums) {
    // dp(i): min num of elements to fill i weight
    vector<int> dp(min_wt + 1, INT_MAX);
    dp[0] = 0;
    
    for(auto num: nums)
        for(int i = min_wt; i >= num; i--) {
            int with_curr = dp[i - num] == INT_MAX ? INT_MAX : dp[i - num] + 1;
            dp[i] = min(dp[i], with_curr);
        }
                
    return dp[min_wt];
}

//TC: O(NW) + O(NW)
int Solution::solve(const vector<int> &nums) {
    // P = (total + 0) / 2, best case scenario for a set
    // to have min min diff
    int total = accumulate(begin(nums), end(nums), 0);
    int set1 = floor(total / 2);
    
    // dp(i): whether possible to have fill knapsack wt j using
    // elements from array only once
    vector<bool> dp(set1 + 1, false);
    // always possible to fill 0 wt knapsack
    dp[0] = true;
    int min_wt = set1;
    int min_set = set1;
    
    for(const int& num: nums) {
        for(int w = set1; w >= num; w--) {
            dp[w] = dp[w] || dp[w - num];
            
            int target = abs(2 * w - total);
            if(dp[w] && target < min_wt) {
                min_wt = target;
                min_set = w;
            }
        }
    }
    
    // check the min number of elements required to fill
    // the min weight knapsack(set1 or set2 whichever is needs to be min)
    int min_num_set = findMinKnapsackElements(min_set, nums);
    return min_num_set;
}
