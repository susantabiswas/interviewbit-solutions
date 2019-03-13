/*
    Partition string with min cuts such that each partition is a palindrome
    https://www.interviewbit.com/problems/palindrome-partitioning-ii/
*/

int findPalindromes(string& str, int i, int j, vector<vector<int>>& dp) {
    if(i < 0 || j < 0 || j >= str.size() || i >= str.size())
        return 0;
        
    // base case
    if(i == j)
        return dp[i][j] = 1;
    if(j - i == 1)
        return dp[i][j] = str[i] == str[j];
        
    if(dp[i][j] == -1) {
        dp[i][j] = findPalindromes(str, i+1, j-1, dp) && str[i] == str[j];
    }
    if(j - 1 >= 0 && dp[i][j - 1] == -1)
        findPalindromes(str, i, j - 1, dp);
    if(i + 1 < str.size() && dp[i + 1][j] == -1)
        findPalindromes(str, i + 1, j, dp);
    return dp[i][j];
}


int Solution::minCut(string str) {
    const int N = str.size();
    // (i, j): whether substring from i to j is palindromic
    vector<vector<int> > dp(N, vector<int>(N, -1));
    // each single character is a palindrome
    for(int i = 0; i < N; i++)
        dp[i][i] = 1;
        
    // find all the palindromes
    findPalindromes(str, 0, N-1, dp);
    
    // each ith entry indicates the min cuts required till that index
    // for having all palindromic partitions
    vector<int> cuts(N, INT_MAX);
    
    for(int i = 0; i < N; i++) {
        // if the substring is palindromic no need for a cut
        if(dp[0][i] == 1) 
            cuts[i] = 0;
        else {
            // find a position where making a cut will involve
            // min total cuts 
            for(int j = 0; j < i; j++) {
                // if for jth index, remaining j+1:i is palindromic
                // and cut at jth index keeps total cuts min
                if(dp[j+1][i] == 1) {
                    if(cuts[j] + 1 < cuts[i])
                        cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[N-1];
}
