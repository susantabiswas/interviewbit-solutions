/*
    https://www.interviewbit.com/problems/painters-partition-problem/
*/

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
