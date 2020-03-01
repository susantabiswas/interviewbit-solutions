/*
    https://www.interviewbit.com/problems/regular-expression-ii/
*/

// Using Tabulation
int regexMatchTab(const string& s, const string& patt) {
    const int M = s.size(), N = patt.size();
    vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, true));
    
    // when source str length is 0, only * is allowed
    for(int i = 1; i <= N; i++)
        dp[0][i] = patt[i-1] == '*' ? ((i-2) >= 0 ? dp[0][i-2] : false) : false;
    // when patt length is 0, always false except when source len is 0
    for(int i = 1; i <= M; i++)
        dp[i][0] = false;
        
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++) {
            // when chars are same
            if(s[i-1] == patt[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                // when patt char is '.'
                if(patt[j-1] == '.') 
                    dp[i][j] = dp[i-1][j-1];
                else if(patt[j-1] == '*') {
                    // we can either use * or not use it
                    // use *, check if the preceeding char is same or '.'
                    int with_star = (j-2 >= 0) && (patt[j-2] == '.' || patt[j-2] == s[i-1]) ?
                                        dp[i-1][j] : false;
                    // don't use *, goto to char before preceeding char
                    int without_star = j-2 >= 0 ? dp[i][j-2] : true;
                    dp[i][j] = with_star || without_star;
                }
                else    // when chars are diff
                    dp[i][j] = false;
            }
        }
    return dp[M][N];
}

int Solution::isMatch(const string s, const string patt) {
    return regexMatchTab(s, patt);
}
