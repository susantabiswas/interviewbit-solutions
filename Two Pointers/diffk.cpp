/*
    find if a(i) + a(j) = k, exists
    https://www.interviewbit.com/problems/diffk/

    TC: O(n)
*/

// Using 2 pointers
/*
    Since the diff needs to be found, we need to start with the smallest
    diff, that is possible when we start either from beginning or end.
    Then based on the diff, we can move the pointer.
    
    TC: O(N), SC: O(1)
*/
int Solution::diffPossible(vector<int> &nums, int target) {
    int left = 0, right = 1;
    while(right < nums.size() && left < right) {
        int diff = nums[right] - nums[left];
        // if the target is found
        if(diff == target)
            return 1;
        // make the diff bigger by making the bigger number bigger
        else if(diff < target)
            ++right;
        // make the diff smaller, by making the smaller number bigger
        else {
            ++left;
            // when both the pointers are at the same position,
            // move the right one
            if(left == right)
                ++right;
        }
    }
    
    return 0;
}

// Using Hashing
// TC: O(N), SC: O(N)
/*int Solution::diffPossible(vector<int> &nums, int target) {
    unordered_set<int> s;
    for(const int& num: nums) {
        if(s.find(-1 * (target - num)) != s.end())
            return 1;
        s.emplace(num);
    }
    return 0;
}
*/

int Solution::diffPossible(vector<int> &arr, int k) {
    int diff = 0;
    for(int i = 0, j = 1; i < arr.size() && j < arr.size(); ) {
        diff = abs(arr[i] - arr[j]);
        if(diff == k)
            return 1;
        else if(diff > k) {
            ++i;
            if(i == j)
                ++j;
        }
        else {
            ++j;
        }
    }
    
    return 0;
}
