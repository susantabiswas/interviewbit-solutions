/*
    Max contingous non negative subarray
    https://www.interviewbit.com/problems/max-non-negative-subarray/?ref=similar_problems
    TC: O(n)
*/

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
