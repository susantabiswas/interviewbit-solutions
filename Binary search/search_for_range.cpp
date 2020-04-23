/*
    Search for a target range
    https://www.interviewbit.com/problems/search-for-a-range/
*/

/*
    Solution 1
    We use two kinds of binary search, for getting the first and last element.
    Then perform the two searches on the entire array to get the [first, last]
    TC: O(logN), SC: O(1)
*/

// returns the first instance of target
int leftBSearch(const vector<int>& nums, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else    // A[mid] >= target
            right = mid - 1;
    }   
    return nums[right + 1] == target ? right + 1 : -1;
}

// returns the last instance of target
int rightBSearch(const vector<int>& nums, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else // A[mid] <= target 
            left = mid + 1;
    }   
    return nums[left-1] == target ? left-1 : -1;
}

                
vector<int> Solution::searchRange(const vector<int> &nums, int target) {
    vector<int> pos(2, -1);

    int start = leftBSearch(nums, 0, nums.size()-1, target);
    int end = rightBSearch(nums, 0, nums.size()-1, target);
    
    pos[0] = start == -1 && end == -1 ? -1 : (start == -1 ? end : start);
    pos[1] = start == -1 && end == -1 ? -1 : (end == -1 ? start : end);
    return pos;
}

// Solution 2
void findRange(const vector<int>& arr, int l, int h, int& k, vector<int>& range,
                bool left) {
    if(l <= h) {
        int mid = l + (h - l) / 2;
        
        // target found, update range
        if(arr[mid] == k) {
            if(range[0] == -1 && range[1] == -1) {
                range[0] = mid;
                range[1] = mid;
            }
            else {
                range[0] = min(mid, range[0]);
                range[1] = max(mid, range[1]);
            }
            // if this is search for lower bound
            if(left)
                findRange(arr, l, mid-1, k, range, left);
            else    // search for upper bound
                findRange(arr, mid+1, h, k, range, left);
        }
        else if(arr[mid] > k)
            findRange(arr, l, mid-1, k, range, left);
        else
            findRange(arr, mid + 1, h, k, range, left);
    }    
}

vector<int> Solution::searchRange(const vector<int> &arr, int k) {
    vector<int> range = {-1, -1};
    // we do two binary searches, each focusing on finding the 
    // extreme end position of target value
    // So we do searches for lower and upper bounds.
    findRange(arr, 0, arr.size() - 1, k, range, true);
    findRange(arr, 0, arr.size() - 1, k, range, false);
    
    return range;
}
