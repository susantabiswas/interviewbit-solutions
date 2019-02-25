/*  Remove target number
    https://www.interviewbit.com/problems/remove-element-from-array/
    TC: O(n)
*/

int Solution::removeElement(vector<int> &arr, int target) {
    // latest index where non target number can be placed
    // till write_idx-1: contains all numbers except for target
    int write_idx = 0;

    // start traversal and when target is seen don't increment write index,
    // so the next number not equal to target will swap with a position where a target 
    // number is
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != target) 
            swap(arr[write_idx++], arr[i]);
    }
    
    return write_idx;
}
