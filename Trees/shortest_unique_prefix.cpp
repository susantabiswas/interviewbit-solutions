/*
    Shortest uncommon prefix for each string, done using Trie
    https://www.interviewbit.com/problems/shortest-unique-prefix/
*/
struct TrieNode{
    bool isString = false;
    int freq = 0;
    unordered_map<char, TrieNode*> leaves;
};

bool insertTrie(string& word, TrieNode*& root) {
    TrieNode* curr = root;
    for(auto& c: word) {
        // check if the node for current character exists
        if(curr->leaves.find(c) == curr->leaves.end()) {
            curr->leaves[c] = new TrieNode();
        }
        // goto to that node and update its freq
        // for the first time while creation it is 1
        curr = curr->leaves[c];
        curr->freq += 1;
    }
    
    if(curr->isString == true)
        return false;
    else {
        curr->isString = true;
        return true;
    }
        
}

string shortestPrefix(TrieNode* root, string str) {
    string prefix;
    TrieNode* curr = root;
    for(auto& c: str) {
        prefix += c;
        
        curr = curr->leaves[c];
        // if this is the first uncommon character
        if(curr->freq == 1)
            return prefix;
    }
    
    return "";
}

bool createTrie(vector<string>& words, TrieNode*& root) {
    for(auto& word: words) {
        insertTrie(word, root);
    }
    return true;
}

vector<string> Solution::prefix(vector<string> &words) {
    TrieNode* root = new TrieNode();
    // create a Trie with the words
    createTrie(words, root);
    
    vector<string> result;
    for(auto& word: words)
        result.emplace_back(shortestPrefix(root, word));
        
    return result;
}
