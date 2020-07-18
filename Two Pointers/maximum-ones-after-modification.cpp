/*
    https://www.interviewbit.com/problems/maximum-ones-after-modification/
    
    Sliding window for max length condition will be used.
    TC: O(N)
    SC: O(1)
*/

int Solution::solve(vector<int> &arr, int char_replacement) {
    int i = 0, j = 0;
    int max_len = 0;
    
    while(i < arr.size()) {
        // expand the window
        if(char_replacement >= 0) {
            if(arr[i] == 0)
                --char_replacement;
            ++i;
        }
        /// make the window valid
        if(char_replacement < 0) {
            if(arr[j] == 0)
                ++char_replacement;
            ++j;
        }
        
        // update max length
        max_len = max(max_len, i - j);
    }
    return max_len;
}
