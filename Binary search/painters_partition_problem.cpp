/*
    https://www.interviewbit.com/problems/painters-partition-problem/
*/
// Variant 1
#include<numeric>
int Solution::paint(int num_painters, int B, vector<int> &boards) {
    // We have num_painters and to complete the total work. Objective is 
    // to minimize the work per painter. If we make each work/painter
    // more then no. of painters required decreases and if we decrease the
    // work/painter then we need more painters as a painter is only allowed
    // to work on contiguous boards. 
    // So we try to find the min work value such that all the painters are utilized.
    // Our search space for work/person is [max_board_length, total_board_length], since partial 
    // painting of board is not allowed, so max board length is the min work.
    
    long long left = *max_element(boards.begin(), boards.end());
    long long right = accumulate(boards.begin(), boards.end(), 0);
    long long min_time = INT_MAX;
    const int MOD = 10000003;
    
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        
        // for the current work, check how many painters will be required
        int painters_req = 1;
        long long curr_time = 0;
        for(const int& length: boards) {
            curr_time += (length) % MOD;
            curr_time %= MOD;
            if(curr_time > mid) {
                ++painters_req;
                curr_time = length;
            }
        }
        
        // based on how the painters are getting utilized, 
        // prune the search space
        
        // when we not using all the painters
        if(painters_req <= num_painters) {
            // check if the currently selected time is the min
            min_time = min(mid, min_time);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return (int)((min_time * (long long)B) % MOD);
}

// Variant 2
int findMinTime(int painters, int time_taken, vector<int>& boards) {

    long long min_length = INT_MAX;
    const int MOD = 10000003;
    // lower limit for length to paint
    int l = *max_element(boards.begin(), boards.end());
    // max sum for length to paint
    long long h = 0;
    for(const auto& a: boards)
        h = h + a;
   
    
    while(l <= h) {
        long long mid = l + (h - l) / 2;
        long long painters_c = 1;
        long long board_len = 0;
        for(int i = 0; i < boards.size(); i++) {
            if((board_len + boards[i]) <= mid) {
                board_len = (board_len + boards[i]);
            }
            else {
                painters_c = painters_c + 1;
                board_len = boards[i];
            }
        }
        
        if(painters_c <= painters) {
            min_length = min(min_length, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    
    return (int)((min_length * (long long)time_taken) % MOD);
}

int Solution::paint(int painters, int time_taken, vector<int>& boards) {
    return findMinTime(painters, time_taken, boards);
}
