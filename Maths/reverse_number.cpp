/*
    reverse an int, check for overflow as well
    https://www.interviewbit.com/problems/reverse-integer/

*/

int Solution::reverse(int num) {
    bool positive = num >= 0;
    
    // make it positive for now
    if(!positive)
        num = num * -1;
    
    long long rev_num = 0;
    
    while(num) {
        if(rev_num > (numeric_limits<int>::max() / 10 + num % 10) )
            return 0;
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    
    // put sign
    if(!positive)
        rev_num *= -1;
    
    return rev_num;
}

