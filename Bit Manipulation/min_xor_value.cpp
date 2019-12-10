/*
    https://www.interviewbit.com/problems/min-xor-value/
    
    TC: O(nlogn)
    Since we want the min XOR and we can get when the two numbers 
    are very similar. Numbers are similar when they are close to each other.
    So we sort the array and find the XOR values for adjacent element pairs.
*/

int Solution::findMinXor(vector<int> &arr) {
    int min_val = numeric_limits<int>::max();
    int curr = 0;
    
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++) {
        // check if current adjacent pair XOR value is min or not
        curr = arr[i] ^ arr[i+1];
        min_val = min(min_val, curr);
    }
    return min_val;
}
