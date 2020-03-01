/*
    https://www.interviewbit.com/problems/regular-expression-match/
*/
// Using memoization
int regexMatchMem(int i, int j, const string& s, const string& patt,
                    vector<vector<int>>& dp) {
    if(dp[i][j] != -1)
        return dp[i][j];
    // base cases
    if(i == 0 && j == 0)
        return dp[i][j] = 1;
    // when source str length is 0, only allowed char is *
    if(i == 0)
        return dp[i][j] = patt[j-1] == '*' ? regexMatchMem(i, j-1, s, patt, dp) : 0;
    if(j == 0)
        return dp[i][j] = 0;
    
    // value not in cache
    if(dp[i][j] == -1) {
        dp[i][j] = 0;    
        // when the chars are same
        if(s[i-1] == patt[j-1])
            dp[i][j] = regexMatchMem(i-1, j-1, s, patt, dp);
        else {
            if(patt[j-1] == '?')
                dp[i][j] = regexMatchMem(i-1, j-1, s, patt, dp);
            else if(patt[j-1] == '*') {
                // When * is used
                int with_star = regexMatchMem(i-1, j, s, patt, dp);
                // when * is not used
                int without_star = regexMatchMem(i, j-1, s, patt, dp);
                dp[i][j] = without_star || with_star;  
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[i][j];
}

// Memoization driver
int regexMatchMemDriver(const string& s, const string& patt) {
    const int M = s.size(), N = patt.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));
    return regexMatchMem(M, N, s, patt, dp);
}

// Using Tabulation
// TC: O(N^2)
int regexMatchTab(const string& s, const string& patt) {
    const int M = s.size(), N = patt.size();
    vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, true));
    
    // when the input str is of length zero, only * is allowed in patt
    for(int i = 1; i <= N; i++)
        dp[0][i] = patt[i-1] == '*' ? dp[0][i-1] : false;
    // when patt length is 0, no match for input str of length other than 0
    for(int i = 1; i <= M; i++)
        dp[i][0] = false;
    
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++) {
            // if the chars are same
            if(s[i-1] == patt[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                // when chars are diff
                // if patt char is ?, then it is allowed
                if(patt[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                // when patt char is '*', then we can either allow the 
                // char is source str or not allow that.
                else if(patt[j-1] == '*') {
                    // using * char, check if match happened before current source char
                    int using_star = dp[i-1][j];
                    // not using * char, check if patt has a match till the current input str
                    int without_star = dp[i][j-1];
                    dp[i][j] = using_star || without_star;
                }
                else // when chars are diff
                    dp[i][j] = false;
            }
        }
            
    return dp[M][N];
}

int Solution::isMatch(const string s, const string patt) {
    return regexMatchMemDriver(s, patt);
    //return regexMatchTab(s, patt);
}
