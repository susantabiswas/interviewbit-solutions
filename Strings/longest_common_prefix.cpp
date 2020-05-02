struct Trie {
    unordered_map<char, Trie*> leaves;
    bool is_string = false;
};

// inserts a node in Trie
bool insert(Trie* root, string s) {
    // start inserting the chars
    for(char& c : s) {
        // node not found
        if(root->leaves.count(c) == 0)
            root->leaves[c] = new Trie;
        root = root->leaves[c];
    }
    // make the string end
    if(!root->is_string)
        return root->is_string = true;
    // word was already inserted
    else
        return false;
}

// Solution 1: Using Trie
// TC: O(nL), n: len of arr, L: longest word length
// TC: O(nL)
string lcpTrie(vector<string>& arr) {
    // create Trie with the words
    Trie* root = new Trie;
    int min_len = INT_MAX;
    string min_word;
    
    for(string& word: arr) {
        insert(root, word);
        
        if(word.size() < min_len) {
            min_len = word.size();
            min_word = word;
        }
    }
        
    // check for the first node, which has more than 1 leaf
    Trie* t = root;
    string common_prefix;
    while(!t->leaves.empty() && t->leaves.size() == 1) {
        common_prefix += (t->leaves.begin())->first;
        t = (t->leaves.begin())->second;
    }
    return common_prefix.size() > min_len ? min_word : common_prefix;
}

//////////////////////////////////////////////////////////////////////////////

// Solution 2: Comparing the strings
// find the prefix for the first two words, then compare 
// the next word with the prefix found so far, shorten the
// prefix if required, do this till the last word of array.
// return whatever prefix is left

// TC: O(N)
string lcpString(vector<string>& arr) {
    string prefix = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        int j = 0, k = 0;
        while(j < prefix.size() && k < arr[i].size()) {
            if(prefix[j] != arr[i][k])
                break;
            ++j, ++k;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

string Solution::longestCommonPrefix(vector<string> &arr) {
    // Using Trie solution
    // return lcpTrie(arr);
    return lcpString(arr);
}




/*
    Longest common prefix
    https://www.interviewbit.com/problems/longest-common-prefix/

    TC: O(m * n), m: length of prefix, n: no. of strings in array
*/

/*
    Since the prefix should be part of every string, so we start with chars of
    string 1, for each char we check at that position in rest of the strings
    their char match or not, whenever any char doesn't match or if the length
    of any string is lesser than current index we quit
*/
string Solution::longestCommonPrefix(vector<string> &arr) {
    string prefix = "";
    bool char_present = true;
    
    if(arr.size() < 1)
        return prefix;
        
    int i = 0;
    while(1) {
        // current char of 1st string which will be checked in other strings
        char current = arr[0][i];
        char_present = true;
        
        // check if this there in all the strings or not
        for(const string s: arr) {
            // if the string length is shorter, then the prefix 
            // can't exist for any longer length
            if(s.size() <= i) {
                char_present = false;
                break;
            }
            
            // if current prefix char isn't there in string then the prefix
            // can't go longer
            if(s[i] != current) {
                char_present = false;
                break;
            }
        }
        
        ++i;
        // since current char is there in every string, append it to prefix string
        if(char_present)
            prefix += current;
        else
            break;
    }
    
    return prefix;
}
