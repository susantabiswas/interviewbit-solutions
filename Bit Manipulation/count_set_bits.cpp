/*
  Count no. of set bits
  https://www.interviewbit.com/problems/number-of-1-bits/
  
  TC: O(d)
*/

int Solution::numSetBits(unsigned int A) {
    int result = 0;
    
    while(A){
        ++result;
        A = A & (A-1);
    }
    return result;
}
