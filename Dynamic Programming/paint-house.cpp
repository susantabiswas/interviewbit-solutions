/*
    https://www.interviewbit.com/problems/paint-house/
    
    For the ith house, we check the cost involved when it is colored
    using each color + min cost required till previous house when 
    it was colored using any other color.
    TC: O(N), SC: O(1)
*/

int Solution::solve(vector<vector<int> > &cost) {
    int cost_red_prev = cost[0][0], cost_green_prev = cost[0][1], 
        cost_blue_prev = cost[0][2];
    int cost_red = 0, cost_green = 0, cost_blue = 0;
    
    for(int i = 1; i < cost.size(); i++) {
        // if current house is colored with red
        cost_red = cost[i][0] + min(cost_green_prev, cost_blue_prev);
        // when green is used
        cost_green = cost[i][1] + min(cost_red_prev, cost_blue_prev);
        // when blue is used
        cost_blue = cost[i][2] + min(cost_red_prev, cost_green_prev);
        
        // set the previous state
        cost_red_prev = cost_red;
        cost_green_prev = cost_green;
        cost_blue_prev = cost_blue;
    }
    return min({cost_red_prev, cost_green_prev, cost_blue_prev});
}
