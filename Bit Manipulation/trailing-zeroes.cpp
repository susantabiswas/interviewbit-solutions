/*
    https://www.interviewbit.com/problems/trailing-zeroes/
    
    TC: O(b), b: no. of bits
*/
int Solution::solve(int n) {
    int zeros = 0;
    while(n) {
        if(n & 1)
            break;
        ++zeros;
        n = n >> 1;
    }
    return zeros;
}
