/*
    Find max water that can be contained between line segments.
    TC: O(n)
    https://www.interviewbit.com/problems/container-with-most-water/

    NOTE: this is very diff from largest rectangle under histogram problem, there
        height was constrained by min height of bars lying in between, here that is not the case 
    
*/

/*
    area = min(h(i), h(j)) * (j - i)
    there are two terms, area increases when the terms increase.
    we start with max (j - i) value, then to find the optimal value for 
    height term, each time we move in direction where the current height is lower
    in hope of finding talle rheight and meanwhile keep track of max height.
*/
int Solution::maxArea(vector<int> &arr) {
    int max_water = 0;
    int curr_water = 0;
    
    int i = 0, j = arr.size() - 1;
    
    while(i < j) {
        curr_water = min(arr[i], arr[j]) * (j - i);
        max_water = max(curr_water, max_water);
            
        if(arr[i] < arr[j])
            ++i;
        else 
            --j;
    }
    
    return max_water;
}
