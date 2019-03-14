/*
    Check if an integer can be represented in A^p , A > 0 and p > 1
    https://www.interviewbit.com/problems/power-of-two-integers/
*/

int Solution::isPower(int num) {
    // can't use log on 1, result is 0
    if(num == 1)
        return 1;
        
    int num_limit = floor(sqrt(num));
    for(int i = 2; i <= num_limit; i++) {
        // find the value of power p
        int p = log10(num) / log10(i);
        
        // check if it i ^ p == num
        if(pow(i, p) == num)    
            return 1;
    }
    return 0;
}
