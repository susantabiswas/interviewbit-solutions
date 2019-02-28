/*
    Find position of an element in a sorted array
    https://www.interviewbit.com/problems/sorted-insert-position/

    TC: O(logn)
*/

int Solution::searchInsert(vector<int> &arr, int k) {
    int l = 0, h = arr.size();
    int mid = 0;
    
    while( l < h) {
        // find the middle element
        mid = l + (h - l) / 2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] > k) {
            h = mid;
        }
        else 
            l = mid + 1;
    }
    
    return arr[mid] < k ? mid + 1 : mid;
}
