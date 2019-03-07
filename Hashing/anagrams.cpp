/*
    Given vector of strings, group them
    https://www.interviewbit.com/problems/anagrams/
*/

vector<vector<int> > Solution::anagrams(const vector<string> &arr) {
    unordered_map<string, vector<int>> groups;
    vector<vector<int>> result;
    
    for(int i = 0; i < arr.size(); i++) {
        string curr_word = arr[i];
        // sort it lexographically
        sort(curr_word.begin(), curr_word.end());
        
        // check if an anagram was already spotted earlier or not
        // if yes then add it to that group
        if(groups.find(curr_word) == groups.end()) {
            groups.emplace(curr_word, vector<int>{i + 1});    
        } 
        else {
            groups[curr_word].emplace_back(i + 1);
        }
    }
    
    // for all lexographically sorted strings, we check if they have made
    // a group or not
    for(auto it = groups.begin(); it != groups.end(); it++) {
       result.emplace_back(move(it->second));
    }
    
    return result;
}
