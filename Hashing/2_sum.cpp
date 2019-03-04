/*
    Find if sum of two numbers equal given sum.
    https://www.interviewbit.com/problems/2-sum/
 */

vector<int> Solution::twoSum(const vector<int> &arr, int k) {
    // since there can be duplicates in array, so we use multimap
    multimap<int, int> nums;
    vector<int> sum_pair;
    
    for(int i = 0; i < arr.size(); i++)
        nums.emplace(arr[i], i);
    
    int opt_i = numeric_limits<int>::max(), opt_j = numeric_limits<int>::max();
    bool found = false;
    for(int i = 0; i < arr.size(); i++) {
        auto res = nums.equal_range(k - arr[i]);
        
        // find j with min index
        int min_idx = numeric_limits<int>::max();
        for(multimap<int,int>::iterator it = res.first; it != res.second; ++it) {
            if(it->second != i)
                min_idx = min(min_idx, it->second);
        }
        if(min_idx != numeric_limits<int>::max() && i < min_idx) {
            found = true;
            if(opt_j > min_idx) {
            
                opt_j = min_idx;
                opt_i = i;
            }
            else if(opt_j == min_idx && opt_i > i) {
            
                opt_i = i;
            }
        }
    }
    
    if(found) {
        sum_pair.emplace_back(opt_i + 1);
        sum_pair.emplace_back(opt_j + 1);
    }
    return sum_pair;
}
