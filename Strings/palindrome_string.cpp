/*
    Check if string is palindromic
    https://www.interviewbit.com/problems/palindrome-string/

    TC: O(n)
*/

int Solution::isPalindrome(string str) {
    for(int i = 0, j = str.size() - 1; i < j; ) {
        // since only alphanumeric chars are allowed, check if
        // they are equal only when both are alphanumeric
        if(isalnum(str[i]) && isalnum(str[j])) {
            if(tolower(str[i]) != tolower(str[j])) {
                return 0;
            }
            ++i, --j;
        }
        else {  // when either is not alphanumeric,
                // move the index char which is not alphanumeric
            if(!isalnum(str[i]))    // when i is not alphanumeric
                ++i;
            else    // when j is not alphanumeric
                --j;
        }
    }
            
    return 1;
}
