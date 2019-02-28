/*
  Reverse bits of a number
  https://www.interviewbit.com/problems/reverse-bits/
  
  TC: O(d)
*/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0;
    int c = 32;
    while(c--){
        // do a left shift
        ans = ans << 1;
        // set the current bit
        ans = ans | (A & 1);
        // go to next bit
        A = A >> 1;
    }
    return ans;
}
