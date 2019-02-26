/* 
    Min steps to reach goal
    https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

    TC: O(n)
*/
/*
    Distance between two pts is max(x_diff, y_diff)
    This is because we can climb up diagonally till one of diff becomes 0,
    then if we continue then that will increase dist for that x or y.
    So we then move along the diretcion whose diff is still +ve
*/
int Solution::coverPoints(vector<int> &x, vector<int> &y) {
    int min_steps = 0;
    int curr_x = 0, curr_y = 0;
    
    for(int i = 0; i < x.size() - 1; i++) {
        curr_x = x[i];
        curr_y = y[i];
        int x_steps = abs(x[i] - x[i+1]);
        int y_steps = abs(y[i] - y[i+1]);
        min_steps += max(x_steps, y_steps);
    }
    return min_steps;
}
