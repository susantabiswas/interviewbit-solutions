/*
    Find length of last word
    https://www.interviewbit.com/problems/length-of-last-word/
    TC: O(n)
*/

// Solution 1
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

// Solution 2
int Solution::lengthOfLastWord(const string str) {
    int i = 0;
    int last_len = 0;
    
    while(i < str.size()) {
        // skip the space chars
        while(i < str.size() && str[i] == ' ')
            ++i;
        
        // next word started
        if(i < str.size() && str[i] != ' ')
            last_len = 0;
            
        // count the length of current word
        while(i < str.size() && str[i] != ' ')
            ++last_len, ++i;
    }
    return last_len;
}
