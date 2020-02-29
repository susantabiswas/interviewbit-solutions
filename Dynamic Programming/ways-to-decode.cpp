/*
    https://www.interviewbit.com/problems/ways-to-decode/
    A message containing letters from A-Z is being encoded to numbers using the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    
    Given an encoded message containing digits, determine the total number of ways to decode it.
*/

// checks if two digit number is valid
bool isValid(int num) {
    return num >= 10 && num <= 26;
}

// TC: O(N)
int Solution::numDecodings(string s) {
    // if the string is empty or if the first is 0, can't be
    // encoded
    if(s.empty() || s[0] == '0')
        return 0;
        
    const int N = s.size();
    vector<unsigned int> dp(N, 0);
    // first char other than 0, can be encoded in 1 way
    dp[0] = 1;
    
    for(int i = 1; i < N; i++) {
        // no. of ways if the current digit is only taken
        int single_digit = s[i] - '0' >= 1 ? dp[i-1] : 0;
        // no. of ways if current digit is taken alongside previous
        // if it is valid, check if this is the first two digit cmb, then
        // there will be 1 way, otherwise it cmb with previous cmb of dp[i-2]
        int two_digits = isValid(stoi(s.substr(i-1, 2))) ? ((i-2) >= 0 ? dp[i-2] : 1) : 0;
        dp[i] = single_digit + two_digits;
        
        // current was 0 and its cmb with previous was > 26, so this portion can't be encoded
        if(dp[i] == 0)
            return 0;
    }
    return dp[N-1];
}
