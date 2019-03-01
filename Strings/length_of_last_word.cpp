/*
    Find length of last word
    https://www.interviewbit.com/problems/length-of-last-word/
    TC: O(n)
*/

int Solution::lengthOfLastWord(const string str) {
    int i = str.size() - 1;
    int end_idx = 0;
    
    // first traverse till the first char from back side
    while(i >= 0 && str[i] == ' ')
        --i;
    // ending index of last word char
    end_idx = i;
    
    // now traverse till we are only getting chars and stop when ' ' is encountered
    while(i >= 0 && str[i] != ' ')
        --i;
        
    return end_idx - i;
}
