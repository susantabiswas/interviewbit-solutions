/*
    https://www.interviewbit.com/problems/word-ladder-i/
    
    TC: O(DL), D: dist of transformation, L:longest word
    Each time only one char can be changed to reach the next vertex. We remove the
    word from set of dictionary words to mark it as visited.
*/
// finds the min no. of transformations using BFS
int BFS(string& start, string& target, unordered_set<string>& words) {
    queue<string> q;
    q.emplace(start);
    // mark visited
    words.erase(start);
    // for keeping track of no. of transformations, this is equal to BFS level
    int level = 0;
    // no. of nodes in current level
    int n_level = q.size();
    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        --n_level;
        
        // if target is reached
        if(curr == target)
            break;
        // for the current word, change each position one at a time
        for(int i = 0; i < target.size(); i++) {
            // save the current char
            char curr_char = curr[i];
            // try putting a-z chars and making words that are in dict.
            for(int j = 0; j < 26; j++) {
                curr[i] = 'a' + j;
                // if the current word is unvisited
                if(words.find(curr) != words.end()) {
                    // mark it visited
                    words.erase(curr);
                    q.emplace(curr);
                }
            }
            // revert the change
            curr[i] = curr_char;
        }
        
        // end of level
        if(n_level == 0) {
            ++level;
            n_level = q.size();
        }
    }
    
    return level + 1;
}

int Solution::solve(string a, string b, vector<string> &c) {
    // set of dictionary words
    unordered_set<string> words(c.begin(), c.end());
    return BFS(a, b, words);
}
