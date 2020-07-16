/*
    https://www.interviewbit.com/problems/an-increment-problem/
    
    TC: O(N)
    SC: O(N)
*/

vector<int> Solution::solve(vector<int> &arr) {
    unordered_map<int, int> pos;
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        if(pos.count(arr[i]) == 0)
            pos[arr[i]] = i;
        // if the element is already there, then the first occurrence
        // of that element will be current + curr_val + 1 be put at the
        // placec where the current element's first occurrence exists currently
        // + check if the new val created < first position of new_val
        else {
            int first_idx = pos[arr[i]];
            int new_val = arr[i] + 1;
            // set the new value in its index
            result[first_idx] = new_val;
            
            // update the position of new value
            if(pos.count(new_val) == 0 || first_idx < pos[new_val])
                pos[new_val] = first_idx;
            pos[arr[i]] = i;
        }
        
        result.emplace_back(arr[i]);
    }
    return result;
}
