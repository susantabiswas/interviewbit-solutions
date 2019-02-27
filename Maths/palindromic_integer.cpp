/*
    Check if a number is palindromic
    https://www.interviewbit.com/problems/palindrome-integer/
    TC: O(d), d: no. of digits
*/

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
