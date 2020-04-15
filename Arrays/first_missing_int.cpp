/*
    https://www.interviewbit.com/problems/first-missing-integer/
*/

// Solution 1
/*
    TC: O(N), SC: O(1)
    
    We use the array as a table for marking the visited numbers in [1:N] range.
    To mark a number as visited we put the number at its index(0-indexed).
    In case we get a number which can't be positioned in the current sized array,
    we proceed for the next element.
    
*/
int Solution::firstMissingPositive(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        // position where the current number should be placed
        int pos_to_go = nums[i] - 1;
        
        // We keep putting numbers while following are true:
        // 1. Current index doesnt match where the current number should be
        // 2. The number can actually be positioned in the current sized array[1:N]
        // 3. The position where the current number should go is not occupied by
        //    a valid number that should be there, in that case current is just a duplicate
        //    and a valid number has been put already.
        while((i != pos_to_go) && 
            (pos_to_go >= 0 && pos_to_go < nums.size()) &&
            ((nums[pos_to_go] - 1)!= pos_to_go)) {
                // put the number at its correct place
                swap(nums[i], nums[pos_to_go]);
                // update the position to go for the current number
                pos_to_go = nums[i] - 1;
            }
    }
    
    // find the first number not at its correct place
    int missing_num = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] - 1 != i) {
            missing_num = i + 1;
            break;
        }
    }
    // if the array contains all the elements in range [1:N], then answer is N+1
    return missing_num == 0 ? nums.size() + 1 : missing_num;
}


// Solution 2
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
