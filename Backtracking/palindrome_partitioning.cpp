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
