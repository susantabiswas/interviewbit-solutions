/*
    https://www.interviewbit.com/problems/flip/
*/

vector<int> Solution::flip(string str) {
    int i = 0;
    int curr = 0, curr_l = 0, curr_r = 0;
    int l = -1, r = -1, max_ones = 0;
    // We use Kaddane's Algo. Every 0 is +1 and 1 is -1.
    // So we find the max contigous subarray that maximizes the score
    while(i < str.size()) {
        int digit = str[i] - '0';
        int curr_score = digit == 1 ? -1 : 1;
        
        if(digit == 1)
            --curr;
        else 
            ++curr;
        
        // if the score is negative, then no point
        // keeping the previous elements in window
        if(curr < curr_score) {
            curr = curr_score;
            curr_l = i, curr_r = i;
        }
        else {
            curr_r = i;
        }
        if(curr > max_ones) {
            max_ones = curr;
            l = curr_l, r = curr_r;
        }
        ++i;
    }
    
    if(l != -1 && r != -1)
        return vector<int>{l+1, r+1};
    return vector<int>{};
}
