/*
    Min jumps to reach end
    https://www.interviewbit.com/problems/min-jumps-array/
*/

int dpSolution(vector<int>& arr) {
    // each ith entry denotes min jumps required to reach i from 0
    vector<int> jumps(arr.size(), INT_MAX);
    jumps[0] = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(jumps[j] != INT_MAX && arr[j] + j >= i) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }            
        }
    }
    return jumps[arr.size() - 1] == INT_MAX ? -1 : jumps[arr.size() - 1];    
}

/*
    While within the reach the current jump, we update the max reachability and
    if in between from a location we can go to last index, then done, else
    we go till the steps for current jump finishes. We travel all the steps for
    a jump.
*/
int greedySolution(vector<int>& arr) {
    if(arr.empty())
        return -1;
    if(arr.size() == 1)
        return 0;
    if(arr[0] >= arr.size() - 1)
        return 1;
        
    int jumps = 1;
    int steps = arr[0];
    int max_reach = arr[0];
    int end_idx = arr.size() - 1;
    
    int i = 0;
    while(i < arr.size()) {
        if(i > max_reach)
            return -1;
            
        // if end is reachable
        if(arr[i] + i >= end_idx)
            return jumps + 1;
            
        // find max reachability 
        max_reach = max(max_reach, arr[i] + i);
       
        if(steps == 0) { 
            // if no further location can be reached
            if(i >= max_reach)
                return -1;
            // we try to travel through all locations,
            // so total steps for next jump is the locations
            // till current max reach
            steps = max_reach - i;
            ++jumps;
        }
        
        --steps;
        ++i;
    }
    return -1;
}

int Solution::jump(vector<int> &arr) {
    // return dpSolution(arr);
    return greedySolution(arr);
}
