/*
    Max contingous non negative subarray
    https://www.interviewbit.com/problems/max-non-negative-subarray/?ref=similar_problems
    TC: O(n)
*/

// Solution1 
vector<int> Solution::maxset(vector<int> &arr) {
    long long max_sum = -1;
    long long curr = INT_MIN;
    int start = -1, end = -1, max_start = -1, max_end = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        // if this the first +ve element in the current subarray
        if(curr < 0 && arr[i] >= 0) {
            start = i, end = i;
            curr = arr[i];
        }
        // if current number is +ve then add to current sum
        else if(arr[i] >= 0) {
            curr += arr[i];
            end = i;    // update end position
        }
        else if(arr[i] < 0) {
            // when current number is -ve, we reset the current sum
            curr = INT_MIN;
        }
        // update max subarray 
        if(curr >= max_sum) {
            // update subarray if currrent sum is more or
            // the subarray length is more and sum is same
            if(curr > max_sum ||
              (curr == max_sum && (end - start) > (max_end - max_start)))
                max_start = start, max_end = end;
        
            max_sum = curr;
        }
    }
   
    return max_sum < 0 ? vector<int>{} : 
                        vector<int>{arr.begin() + max_start, arr.begin() + max_end + 1};
}


// Solution 2
vector<int> Solution::maxset(vector<int> &arr) {
    long long max_sum = 0, curr_sum = 0;
    vector<int> max_subarray;
    vector<int> curr_subarray;
    
    for(int i = 0; i < arr.size(); i++) {
        // if current number is +ve add to subarray
        if(arr[i] >= 0) {
            curr_subarray.emplace_back(arr[i]);
            curr_sum += arr[i];
        }
        else {
        // if current number is negative then check if current
        // +ve subaray is max or not
            if(max_sum < curr_sum) {
                // remove the previous max and put current
                max_subarray.erase(max_subarray.begin(), max_subarray.end());
                max_subarray = move(curr_subarray);
                max_sum = curr_sum;
            }
            else if(max_sum == curr_sum) {
                // add current only if its length is greater
                if(curr_subarray.size() > max_subarray.size()) {
                    // remove the previous max and put current
                    max_subarray.erase(max_subarray.begin(), max_subarray.end());
                    max_subarray = move(curr_subarray);
                    
                    max_sum = curr_sum;
                }
            }
            
            curr_subarray.erase(curr_subarray.begin(), curr_subarray.end());
            curr_sum = 0;
        }
    }
    
    if(max_sum < curr_sum) {
        // remove the previous max and put current
        max_subarray.erase(max_subarray.begin(), max_subarray.end());
        max_subarray = move(curr_subarray);
        max_sum = curr_sum;
    }
    
    return max_subarray;
}
