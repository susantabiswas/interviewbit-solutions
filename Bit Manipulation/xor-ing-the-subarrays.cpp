/*
    https://www.interviewbit.com/problems/xor-ing-the-subarrays/
    
    Observations:
    1. XOR of same value 'val' over odd number of times is itself otherwise 0.
    2. for the ith element, there are (N-i) * (i+1) subgroups in which it appears.
    
    So for each element, we check if it will have odd of number of occurrences or
    not, if yes then XOR with final answer.
    TC: O(N)
*/

int Solution::solve(vector<int> &arr) {
    long long xor_val = 0;
    const int N = arr.size();
    
    for(int i = 0; i < arr.size(); i++) {
        long long occurrences = (N - i) * (i + 1);
        if(occurrences % 2 != 0)
            xor_val ^= arr[i];
    }
    return xor_val;
}
