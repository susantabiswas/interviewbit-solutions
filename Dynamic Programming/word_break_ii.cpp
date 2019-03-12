/*
    Word break II
    https://www.interviewbit.com/problems/word-break-ii/
*/

void formSentence(string& str, int curr, set<string>& words, 
                string partial, vector<string>& result, vector<bool>& decomposable) {
    if(curr == str.size()) {
        result.emplace_back(partial);
    }
    
    for(int i = curr; i < str.size(); i++) {
        // current substring is a dict word
        string curr_word = str.substr(curr, i - curr + 1);
        // if current substring is there in dict and [i:n-1] is decomposable
        if(words.find(curr_word) != words.end() && decomposable[i+1]) {
            string new_word;
            // if this is not the first word add space in front
            if(!partial.empty())
                new_word += ' ';
            new_word += curr_word;
            
            // if after adding the word ending at 'i', we get to know
            // that remaining string couldnt be decomposed into words,
            // we mark this index as non decomposable
            int old_size = result.size();
            formSentence(str, i+1, words, partial + new_word, result, decomposable);
            if(old_size == result.size()) 
                decomposable[i+1] = false;
        }
    }
}

vector<string> Solution::wordBreak(string str, vector<string> &dict) {
    set<string> words;
    // each ith entry means that string from [i:n-1] is decomposable
    // into words
    vector<bool> decomposable(str.size() + 1, true);
    for(const auto& a: dict)
        words.emplace(a);
        
    vector<string> result;
    string partial;
    formSentence(str, 0, words, partial, result, decomposable);
    sort(result.begin(), result.end());
    
    return result;
}
