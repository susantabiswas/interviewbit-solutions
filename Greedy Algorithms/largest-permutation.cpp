/*
    https://www.interviewbit.com/problems/largest-permutation/
    
    Since the largest cmb will have the biggest numbers in front, 
    so just need to make sure we do whenever we can, in this case it
    can be done k times.
    Since numbers are in 1-N range, so all of them are unique for the 
    array, we make a mapping of index. Then start a traversal such that
    for each position where the the largest number that is supposed to be 
    there is not there we make a swap using the idx mapping.
    
    TC: O(N)
    SC: O(N)
*/

vector<int> Solution::solve(vector<int> &arr, int k) {
    // mapping of index 
    unordered_map<int, int> idx;
    for(int i = 0; i < arr.size(); i++)
        idx[arr[i]] = i;
    
    // largest element for the current position
    int greatest = arr.size();
    for(int i = 0; k && i < arr.size(); i++) {
        // if the position doesn't match, we need to do a swap
        if(arr[i] != greatest) {
            int greatest_idx = idx[greatest];
            // update the mapping idx in hash table
            idx[arr[i]] = greatest_idx;
            idx[greatest] = i;
            swap(arr[i], arr[greatest_idx]);
            --k;
        }
        --greatest;
    }
    return arr;
}
