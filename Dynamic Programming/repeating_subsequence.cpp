/*
    Find repeating subsequence
    https://www.interviewbit.com/problems/repeating-subsequence/

*/

/*
    Repeating sequence for a string will be common substrings starting at different positions.
    So we find the LCS ensuring that we dont match if the index is same
*/
int findLCS(string& str, int i, int j, vector<vector<int>>& dp) {
    if(i < 0 || j < 0)
        return 0;
        
    if(dp[i][j] == -1) {
        // same character iff i != j
        if(str[i] == str[j] && i != j) {
            dp[i][j] = 1 + findLCS(str, i - 1, j - 1, dp);
        }
        else {
            dp[i][j] = max(findLCS(str, i, j - 1, dp),
                                findLCS(str, i - 1, j, dp));
        }
    }
    
    return dp[i][j];
}

int Solution::anytwo(string str) {
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
    int lcs = findLCS(str, str.size() - 1, str.size() - 1, dp);
    return lcs >= 2;
}
