/*
    https://www.interviewbit.com/problems/tushars-birthday-party/
    TC: O(MN), M: no. of friends, N: No. of food items
*/
int Solution::solve(const vector<int> &friends, 
            const vector<int> &foods, const vector<int> &prices) {
    if(friends.empty())
        return 0;
        
    int cost = 0;
    // Find the min cost for each friend, sum of all the min cost is the answer
    for(const int& friend_cap: friends) {
        vector<int> dp(friend_cap + 1, INT_MAX);
        dp[0] = 0;
        
        // find the min cost for current friend
        // This is like knapsack problem or coin change
        for(int i = 0; i < foods.size(); i++) {
            for(int j = 1; j <= friend_cap; j++) {
                int with_curr = (j - foods[i] >= 0) ? dp[j - foods[i]]: INT_MAX;
                if(with_curr != INT_MAX)
                    dp[j] = min(dp[j], prices[i] + with_curr);
            }
        }
        // add the cost for current friend
        cost += dp[friend_cap];
    } 
    return cost;
}
