/*
    https://www.interviewbit.com/problems/first-repeating-element/
    
    We use a hash table to keep track of first position for
    each unique element. Also track the smallest index out of all the
    repeating indices.
    
    TC: O(N)
    SC: O(N)
*/
int Solution::solve(vector<int> &arr) {
    unordered_map<int, int> pos;
    int min_pos = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++) {
        // if the element was seen before, check if it has 
        // the min starting index
        if(pos.count(arr[i]))
            min_pos = min(min_pos, pos[arr[i]]);
        else
            pos[arr[i]] = i;
    }
    return min_pos == INT_MAX ? -1 : arr[min_pos];
}
