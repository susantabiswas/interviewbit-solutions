/*
    Can end be reached using jumps
    https://www.interviewbit.com/problems/jump-game-array/
*/

int Solution::canJump(vector<int> &arr) {
    int reach = 0;
    int curr_max_index = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        // position that can be reached from current position
        curr_max_index = i + arr[i];
        
        // if the current position can be reached, then check how far
        // can we go
        if(reach >= i)
            reach = max(reach, curr_max_index);
        // when reaching atleast the last index is possible
        if(reach >= arr.size() - 1)
            return 1;
    }
    return 0;
}
