/*
    https://www.interviewbit.com/problems/subarray-with-given-xor/
    
    Use hash table to keep track of cummulative XOR values and check for
    number of subarrays ending with curr_xor ^ B.
    
    TC: O(N)
    SC: O(N)
*/

int Solution::solve(vector<int> &arr, int B) {
    // (xor value, number of positions ending with the value)
    unordered_map<int, int> xors;
    int xor_val = 0, subarrays = 0;
    
    // empty array has XOR value of 0
    xors[0] = 1;
    for(int i = 0; i < arr.size(); i++) {
        xor_val = xor_val ^ arr[i];
        // Since XOR is cummutative and distributive, check
        // if we have seen B ^ curr value before
        if(xors.count(B ^ xor_val))
            subarrays += xors[B ^ xor_val];
        // increment for the current XOR value
        xors[xor_val] += 1;
    }
    return subarrays;
}
