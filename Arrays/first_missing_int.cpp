/*
    https://www.interviewbit.com/problems/first-missing-integer/
*/
// Solution 1
/*
    TC: O(n), SC: O(1)
    We use the array as hash table for [1:N].
    For each element, if it is in [1:N] and not in 
    its correct position, then we swap that to its correct
    position. We keep swapping till that position has the
    correct element and not that the current element is at its
    current position. This is important in case there are duplicates
    [1, 1, 1], we try to insure that each element is at its current pos. we can 
    get into a infinite loop. So only insuring that each pos has the correct element
    is enough.
    
    Then we traverse the array and see for a number 'i' in [1:N] that is not at
    its correct pos., that is returned
*/
int Solution::firstMissingPositive(vector<int>& arr) {
    const int N = arr.size();
    for(int i = 0; i < arr.size(); i++) {
        // if current number is in [1:N], then
        // we just put it at its current position,
        // we ensure that element 'i' is at (i-1)th position(0 indexed)
        while((arr[i] > 0 && arr[i] <= N) &&
                arr[arr[i] - 1] != arr[i])
            swap(arr[i], arr[arr[i] - 1]);
    }
    
    // find the missing 
    for(int i = 0; i < N; i++) {
        if(arr[i] != (i+1))
            return i+1;
    }
    return N+1;
}

// Solution 2
// TC: O(nlogn), SC: O(n)
/*int Solution::firstMissingPositive(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int missing = 1;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == missing)
            ++missing;
    }
    return missing;
}*/
