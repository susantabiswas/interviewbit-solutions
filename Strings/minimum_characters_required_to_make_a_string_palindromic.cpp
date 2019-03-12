/*
  Minimum number of characters required to make a string palindromic.
  https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
*/

/*
    We just need to find the length of the longest palindrome starting 
    index 0, since the chars will be inserted in the beginning, so whatever
    chars are not part of palindrome will be inserted in front.
    
    Now to search for longest palindrome, we can do it effieciently by creating
    longest proper suffix from the end of the string matching the front of the string.
    
    Then we traverse the created table, and check for a value whose either
    previous(i-1) or previous to previous(i-2) index is equal to the no. of chars
    matching there from back. Keep track of max.
*/

// create proper suffix table
vector<int> createProperPrefix(string& str) {
    vector<int> suffix(str.size(), 0);
    int j = 0;
    for(int i = suffix.size() - 1; i >= 0; ) {
        if(str[i] == str[j]) {
            suffix[i] = j + 1;
            ++j, --i;
        }
        else {
            if(j != 0) {
                j = suffix[j-1];
            }
            else {
                j = 0;
                --i;
            }
        }
    }
    return suffix;
}

int Solution::solve(string str) {
    // compute the lps
    vector<int> suffix = createProperPrefix(str);
    int longest_palindrome = 0;
    
    for(int i = 0; i < str.size(); i++) {
        // if a palindrome is formed starting [0: i + suffix[i]] 
        if(suffix[i] != 0) {
            // if ith position is just adjacent to middle index of palindrome
            // we consider both even and odd lengths
            if(i-1 >= 0 && i-1 == suffix[i] - 1 ||
                i-2 >= 0 && i-2 == suffix[i] -1)
                longest_palindrome = max(longest_palindrome, i + suffix[i] - 1);
        }
    }
    
    return str.size() - longest_palindrome - 1;
}
