/*
    Check if a string can be broken into words from a dictionary
    https://www.interviewbit.com/problems/word-break/
*/

bool isStringDecomposable(string& str, int curr, set<string>& words,
                            vector<bool>& decomposable) {
    if(curr == str.size()) {
        return true;
    }
    
    // we try all the substrings starting current position and check
    // if they create a word from the dict or not iff the index
    // is decomposable
    for(int i = curr; i < str.size(); i++) {
        if(decomposable[i]) {
            string curr_word = str.substr(curr, i - curr + 1);
            // if the substring exists in dict
            if(words.find(curr_word) != words.end()) {
                if(isStringDecomposable(str, i + 1, words, decomposable))
                    return true;
                else
                    decomposable[i] = false;
            }
        }
    }
    
    return false;
}

int Solution::wordBreak(string str, vector<string> &dict) {
    // hash table for words
    set<string> words(dict.begin(), dict.end());
    // each ith entry indicates that [i:n-1] can be decomposed into words
    // from dictionary
    vector<bool> decomposable(str.size(), true);
    return isStringDecomposable(str, 0, words, decomposable);
}
