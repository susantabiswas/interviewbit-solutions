/*  
  Find the max sum of contiguous elements of an array
  https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/

int Solution::maxSubArray(const vector<int> &arr) {
    int max_sum = numeric_limits<int> :: min();
    int curr_sum = 0;
    int max_neg = numeric_limits<int> :: min();
    
    for(int i = 0; i < arr.size(); i++) {
        // find the maximum negative number, incase all the numbers are -ve
        if(arr[i] < 0)
            max_neg = max(max_neg, arr[i]);
        // if the sum has become negative, no point of having sum of last values
        // start taking the subarray sum from current
        if(curr_sum <= 0) {
            curr_sum = arr[i];
        }
        // add the current element if sum is still +ve
        else
            curr_sum += arr[i];
        
        max_sum = max(max_sum, curr_sum);
    }
    
    
    return max(max_sum, max_neg);
}
