/*
    Find the longest palindromic substring
    https://www.interviewbit.com/problems/longest-palindromic-substring/
*/

// DP solution
int longestPalindromeString(string str, int i, int j, vector<vector<int>>& dp, 
                            int& max_s, int& max_e, int& max_len) {
    // base case
    if(i < 0 || j < 0 || i >= str.size() || j >= str.size())
        return 0;
    // when single character
    if(i == j)
        return dp[i][j] = 1;
    // when only two same characters are there
    if(j - i == 1)
        return dp[i][j] = (str[i] == str[j]);
        
    if(dp[i][j] == -1) {
        dp[i][j] = longestPalindromeString(str, i+1, j-1, dp, max_s, max_e, max_len)
                    && (str[i] == str[j]);
        if(j - 1 >= 0)
            longestPalindromeString(str, i, j-1, dp, max_s, max_e, max_len);
        if(i+1 < str.size())
            longestPalindromeString(str, i+1, j, dp, max_s, max_e, max_len);
    }   

    return dp[i][j];
}

string dpSolution(string& str) {
    const int N = str.size();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    
    for(int i = 0; i < str.size(); i++)
        dp[i][i] = 1;
    int max_len = 1;
    int max_s = 0, max_e = 0;
    longestPalindromeString(str, 0, str.size() - 1, dp, max_s, max_e, max_len);

    // find longest palindrome
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) {
            int curr_len = j - i + 1;
            if(dp[i][j] == 1 && curr_len > max_len || 
              (curr_len == max_len && i < max_s)) {
                max_s = i;
                max_e = j;
                max_len = curr_len;
            }
        }
    }
    return str.substr(max_s, max_len);
}


// checks if current position is a palindrome center or not
bool isPalindromeCenter(string& str, int& max_len, int curr,
                    bool even, string& longest_palindrome) {
    int j;
    int k;
    
    if(even) {
        j = curr - 1;
        k = curr;
    }
    else {
        j = curr;
        k = curr;
    }
    
    while(j >= 0 && k < str.size()) {
       if(str[j] != str[k]) {
           break;
       } 
       --j, ++k;
    }
    // position j and k such that j and k are at starting and ending 
    // positions of palindrome candidate
    ++j;
    --k;
    // when string of size 2 and not a palindrome
    if(j > k)
        return false;
        
    int curr_length = k - j + 1;
    // update max palindrome length
    if(curr_length > max_len) {
        max_len = curr_length;
        longest_palindrome = str.substr(j, curr_length);
    }
}

string Solution::longestPalindrome(string str) {
    if(str.size() == 0)
        return "";
        
    // dpSolution(str);
    int max_len = 1;
    string longest_palindrome = str.substr(0, 1);
    for(int i = 1; i < str.size(); i++) {
        // for even length palindrome
        // i represents the center
        isPalindromeCenter(str, max_len, i, true, longest_palindrome);
        // for odd length palindrome
        isPalindromeCenter(str, max_len, i, false, longest_palindrome);
    }
    
    return longest_palindrome;
}
