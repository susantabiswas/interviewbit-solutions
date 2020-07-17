/*
    https://www.interviewbit.com/problems/longest-subarray-length/
    
    Idea is to keep a cummulative sum with +1 for 1 and -1 for 0.
    Then save the position of each unique cummulative sum, for any valid
    region sum value we will get  sum_value-1 position also, i.e the value
    just before the start of the subarray, keep track of max such length.
    TC: O(N)
    SC: O(N)
*/
int Solution::solve(vector<int> &arr) {
    int max_len = 0, cumm_sum = 0;
    // (cummulative sum, index)
    unordered_map<int, int> pos;
    // empty array position
    pos[0] = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        cumm_sum = cumm_sum + (arr[i] == 1 ? 1 : -1);
        // value - 1, indicates presence of more 1s than 0s, check 
        // if exists
        if(pos.count(cumm_sum - 1))
            max_len = max(max_len, i - pos[cumm_sum - 1]);
        if(pos.count(cumm_sum) == 0)
            pos[cumm_sum] = i;
    }
    return max_len;
}
