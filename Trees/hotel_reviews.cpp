/*
    Trie question
    https://www.interviewbit.com/problems/hotel-reviews/
*/

struct TrieNode {
    bool isString = false;
    unordered_map<char, TrieNode*> leaves;
};

bool insertTrie(string word, TrieNode* root) {
    for(auto& c: word) {
        if(root->leaves.find(c) == root->leaves.end())
            root->leaves[c] = new TrieNode();
        
        root = root->leaves[c];
    }
    
    if(root->isString == true) {
        return false;
    }
    else {
        root->isString = true;
        return true;
    }
}

int findString(string word, TrieNode* root) {
    for(auto& c: word) {
        // if the current character is not found
        if(root->leaves.find(c) == root->leaves.end())
            return 0;
        root = root->leaves[c];
    }
    
    // check the current word is present in good words list
    if(root->isString == true)
        return 1;
    else
        return 0;
}

vector<int> Solution::solve(string good_words, vector<string> &reviews) {
    TrieNode* root = new TrieNode();
    
    istringstream g_words(good_words);
    string word;
    
    // create Trie of good words
    while(getline(g_words, word, '_')) {
        insertTrie(word, root);
    }
    
    struct ReviewInfo {
        int idx;
        int score;
        ReviewInfo(int idx, int score) : idx(idx), score(score) {} 
    };
    
    // for stroing the score values for each string
    vector<ReviewInfo> scores;
    // for each review we will count number of good words it has
    for(int i = 0; i < reviews.size(); i++) {
        int score = 0;
        istringstream r_words(reviews[i]);
        // get eaech word from current review
        while(getline(r_words, word, '_')) {
            score += findString(word, root);
        }
        
        scores.emplace_back(ReviewInfo(i, score));
    }
    
    // sort the reviews by score
    sort(scores.begin(), scores.end(), [](const ReviewInfo& a, const ReviewInfo& b)->bool{
        if(a.score == b.score)
            return a.idx < b.idx;
        return a.score > b.score;
    });
    
    vector<int> result;
    for(const auto& a: scores)
        result.emplace_back(a.idx);
        
    return result;
}
