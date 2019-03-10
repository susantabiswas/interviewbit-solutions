/*
    Check if a string is formed from interleaving of two strings
    https://www.interviewbit.com/problems/interleaving-strings/
*/

int checkInterleaving(string& a, int i, string& b, int j, string& c, int k,
                    vector<vector<int> >& dp) {
    // when all the lengths are 0
    if(i == 0 && j == 0 && k == 0)
        return dp[i][j] = 1;
    
    if(dp[i][j] == -1) {
        // when only string b is left
        if(i == 0 && j > 0) {
            dp[i][j] = checkInterleaving(a, i, b, j-1, c, k-1, dp) && b[j-1] == c[k-1];
        }   
        // when oonly string a is left
        else if(i > 0 && j == 0) {
            dp[i][j] = checkInterleaving(a, i-1, b, j, c, k-1, dp) && a[i-1] == c[k-1];
        }
        // when both the strings are left, we check if both the strings's
        // last chars equals c's last char or not, if they are equal then we check
        // for both combinations
        else if(i > 0 && j > 0) {
            dp[i][j] = checkInterleaving(a, i-1, b, j, c, k-1, dp) && (a[i-1] == c[k-1]) ||
                        checkInterleaving(a, i, b, j-1, c, k-1, dp) && (b[j-1] == c[k-1]);
        }
    }
    
    return dp[i][j];
}

int Solution::isInterleave(string a, string b, string c) {  
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
    // when c size is not equal to sum of a and b
    if(a.size() + b.size() != c.size())
        return 0;
    checkInterleaving(a, a.size(), b, b.size(), c, c.size(), dp);

    return dp[a.size()][b.size()];
}
