/*
  Find the maximum unsorted subarray
  https://www.interviewbit.com/problems/maximum-unsorted-subarray/
*/
vector<int> Solution::subUnsort(vector<int> &nums) {
    int first = -1, second = -1;
    int range_min = INT_MAX, range_max = INT_MIN;
    
    for(int i = 0; i < nums.size() - 1; i++) {
        // find the term which doesnt follow the order
        if(nums[i] > nums[i+1]) {
            // if this is the first index that doesnt follow the order
            if(first == -1)
                first = i;
            // update the last term not following the order
            second = i+1;
            range_min = min(range_min, nums[i+1]);
            range_max = max(range_max, nums[i]);
        }
    }
    // now we know the minimum range that needs to sorted,
    // we check if there is an element > min on left and element < max
    // on right
    
    // we check for the first element which is bigger as
    // all the numbers after that should be sorted
    for(int i = 0; i < first; i++) 
        if(nums[i] > range_min) {
            first = i;
            break;
        }
            
    // we check for the last element which is smaller as all the numbers
    // before it should be sorted
    for(int i = nums.size() - 1; i > second; i--) 
        if(nums[i] < range_max) {
            second = i;
            break;
        }
    
    return first == -1 ? vector<int>{-1} : vector<int>{first, second};
}


vector<int> Solution::subUnsort(vector<int> &arr) {
    int s = INT_MAX;
    int e = INT_MIN;
    int min_el = INT_MAX;
    int max_el = INT_MIN;
    bool unsorted = false;
    
    // find the candidate unsorted region
    for(int i = 1; i < arr.size(); i++) {
        // order is not maintained
        if(arr[i-1] > arr[i]) {
            s = min(s, i-1);
            e = max(e, i);
        }
    }
    
    // find min and max in unsorted range
    if(s != INT_MAX)
        for(int i = s; i <= e; i++) {
            min_el = min(min_el, arr[i]);
            max_el = max(max_el, arr[i]);
        }
        
        
    int start = 0, end = arr.size() - 1;
    if(s != INT_MAX) {
        // check where the min and max can be placed
        // in sorted parts
        for(int i = 0; i < arr.size(); i++) {
            if(i < s && arr[i] <= min_el) 
                start = max(start, i + 1);
            if(i > e && arr[i] >= max_el)
                end = min(end, i - 1);
        }
    }
    // update the start and end indices if it was found that unsorted region
    // extends more than the candidate region
    int final_s = min(start, s);
    int final_e = max(end, e);
    return s == INT_MAX ? vector<int>{-1} : vector<int> {final_s, final_e};
}
