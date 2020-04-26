/*
    https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
    
    Idea is to keep track of cummulative sum, whenever we see the same sum, it means
    the window in between became 0.
    
    TC: O(N), SC: O(N)
*/

vector<int> Solution::lszero(vector<int> &nums) {
    unordered_map<int, int> cumm_sum_pos;
    // starting position
    cumm_sum_pos[0] = -1;
    int max_len = 0, curr_sum = 0, start=-1, end=-1;
    
    for(int i = 0; i < nums.size(); i++) {
        curr_sum += nums[i];
        int curr_len = 0;
        // check if the sum existed
        if(cumm_sum_pos.count(curr_sum))
            curr_len = i - cumm_sum_pos[curr_sum];
        // add the curr cummulative sum
        else
            cumm_sum_pos[curr_sum] = i;
        
        if(curr_len > max_len) {
            max_len = curr_len;
            start = cumm_sum_pos[curr_sum] + 1, end = i;
        }
    }
    
    return start != -1 ? 
        vector<int>(nums.begin() + start, nums.begin() + end + 1) :
        vector<int>{};
}
