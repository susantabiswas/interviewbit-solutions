// SOLUTION 1

/*
    The idea is to add a substring which is palindromic as 
    prt of partitioned string. 
    For index 'i' start traversig from i to N, then check if S[i:j]
    i <= j <= N, is palindromic, if palindromic then recurse for 
    the string starting j+1.
*/

// finds the palindromic substrings
vector<vector<bool>> findPalindromicSubstrings(string& s) {
    const int N = s.size();
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    
    // all single chars are palindrome
    for(int i = 0; i < N; i++)
        dp[i][i] = true;
    // pick the substrings length wise
    for(int l = 1; l < N; l++) {
        for(int i = 0; i < N - l; i++) {
            int j = i + l;
            // if the substring length is 2
            if(j == i + 1)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
    } 
    
    return dp;
}

void palindromicPartitions(int curr, string& s, 
                        vector<string> partial,
                        vector<vector<bool>>& dp,
                        vector<vector<string>>& result) {
    if(curr == s.size()) {
        result.emplace_back(move(partial));
        return;
    }
    
    for(int i = curr; i < s.size(); i++) {
        string substring = s.substr(curr, i - curr + 1);
        // if the current substring is palindromic
        if(dp[curr][i]) {
            partial.emplace_back(substring);
            palindromicPartitions(i+1, s, partial,
                            dp, result);
            partial.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string s) {
    // find the palindromic substrings
    auto dp = findPalindromicSubstrings(s);
    vector<vector<string>> result;
    
    palindromicPartitions(0, s, vector<string>{}, dp, result);
    return result;
}

////////////////////////////////////////////////////////////

// SOLUTION 2
// checks if a string is palindrome or not
bool isPalindrome(string str) {
    if(str.size() == 0)
        return true;
        
    for(int i = 0, j = str.size() - 1; i < j; i++, j--)
        if(str[i] != str[j])
            return false;
    return true;    
}

/*
    We take a substring and check if it is palindromic, if palindromic add,
    then proceed with the ramaining characters
*/
void findPalindromePartitions(string str, int curr, vector<string> partial,
                                vector<vector<string>>& result) {
    if(curr == str.size()) {
        result.emplace_back(partial);
        return;
    }
    
    for(int i = curr; i < str.size(); i++) {
        string substring = str.substr(curr, i - curr + 1);
        if(isPalindrome(substring)) {
            partial.emplace_back(substring);
            findPalindromePartitions(str, i + 1, partial, result);
            partial.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string str) {
    vector<vector<string>> result;
    vector<string> partial;
    int curr = 0;
    
    findPalindromePartitions(str, curr, partial, result);
    sort(result.begin(), result.end());
    return result;
}
