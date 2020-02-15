/*
    https://www.interviewbit.com/problems/word-ladder-ii/
    
    All possible shortest transformations using BFS.
    TC: O(DL), D: transformation length, L:length of longest word
    SC: O(n * DL), n: no. of possbile transformations
*/
vector<vector<string> > Solution::findLadders(string start, string target, vector<string> &dict) {
    // keeps track of unvisited words
    unordered_set<string> words(dict.begin(), dict.end());
    // all shortest transformations
    vector<vector<string>> result;
    queue<pair<string, vector<string>>> q;
    q.emplace(make_pair(start, vector<string>{start}));
    
    // keeps track of level of BFS
    int level = 0;
    // keeps track of no. of nodes in current levele
    int n_level = q.size();
    while(!q.empty()) {
        pair<string, vector<string>> curr = q.front();
        q.pop();
        // mark it visited 
        words.erase(curr.first);
                
        // if current word is target, add the transformation
        if(curr.first == target) {
            result.emplace_back(curr.second);
        }
        
        // change chars one at a time
        for(int i = 0; i < target.size(); i++) {
            char curr_char = curr.first[i];
            for(int j = 0; j < 26; j++) {
                curr.first[i] = 'a' + j;
                // add dummy state
                curr.second.emplace_back("#");
                // add the woord if unvisited
                if(words.find(curr.first) != words.end()) {
                    // add word to transformation
                    curr.second.back() = curr.first;
                    // NOTE: We don't mark it visited here
                    // because otherwise the multiple shortest 
                    // paths which are possible with some common
                    // nodes won't be possible, like END node will be
                    // common for all.
                    q.emplace(curr);
                }
                // remove the dummy state
                curr.second.pop_back();
            }
            // revert the change
            curr.first[i] = curr_char;
        }
        --n_level;
        // level end
        if(n_level == 0) {
            n_level = q.size();
            // if there are transformations in result for current
            // level, then no point going further
            //if(result.empty() == false)
            //    break;
            ++level;
        }
    }
    //for(auto v: result){for(auto a: v)cout<<a<<" ";cout<<endl;}
    return result;
}
