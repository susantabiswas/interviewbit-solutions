/*
    Remove duplicates from sorted array
    https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
    TC: O(n)
*/

int Solution::removeDuplicates(vector<int> &arr) {
    int write_idx = 1;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i-1])
            arr[write_idx++] = arr[i];
    }
    return write_idx;
}
