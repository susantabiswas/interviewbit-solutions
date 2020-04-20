/*
    https://www.interviewbit.com/problems/sorted-insert-position/
    
    TC: O(logN)
*/
int Solution::searchInsert(vector<int> &arr, int target) {
    // our search space is [0:N] instead of [0:N-1] because
    // the target might be the last element to be inserted
    int left = 0, right = arr.size();
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        // since we need to find the proper index 
        // where the element should exists, so
        // if [left:right-1] is the potential search space,
        // we take right instead of right-1, because the element
        // might be the last one to be inserted
        else if(arr[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}
