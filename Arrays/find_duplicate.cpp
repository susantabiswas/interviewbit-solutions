/* 
    Find the duplicate element
    https://www.interviewbit.com/problems/find-duplicate-in-array/
    TC: O(n)
*/
/*
    Take XOR of range [1:N] and array, then take XOR of both, each number]
    will cancel each other except for the one which has repeated
*/
int Solution::repeatedNumber(const vector<int> &arr) {
    int total_xor = 0;
    
    // take XOR of all [1:n] numbers
    for(int i = 1; i < arr.size(); i++) {
        total_xor ^= i;    
    }
    
    // take XOR of all elements in given range
    int range_xor = 0;
    for(int i = 0; i < arr.size(); i++)
        range_xor ^= arr[i];
    
    return range_xor ^ total_xor ? range_xor ^ total_xor : -1; 
}   

