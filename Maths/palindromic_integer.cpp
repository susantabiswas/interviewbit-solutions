/*
    Check if a number is palindromic
    https://www.interviewbit.com/problems/palindrome-integer/
    TC: O(d), d: no. of digits
*/

// Sol 1
int Solution::isPalindrome(int num) {
    if(num < 0)
        return 0;
    int lsb = 1, msb = pow(10, (int)log10(num));
    while(lsb < msb) {
        if((num / msb)%10 != (num / lsb)%10)
            return 0;
        msb /= 10;
        lsb *= 10;
    }
    return 1;
}

// Sol 2
int Solution::isPalindrome(int num) {
    // just reverse the number and check if they match
    long long rev_num = 0;
    
    if(num < 0)
        return 0;
        
    int temp = num;
    while(temp) {
        rev_num = rev_num * 10 + temp % 10;
        temp = temp / 10;
    }
    
    return rev_num == num;
}
