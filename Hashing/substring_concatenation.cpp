/*
    Find indices starting where the concatenation of dict words exists
    https://www.interviewbit.com/problems/substring-concatenation/
*/

bool checkConcatenation(string sentence, int SIZE, unordered_map<string, int>& word_freq) {
    unordered_map<string, int> freq;

    for(int i = 0; i < sentence.size(); i += SIZE) {
        // take out the current substring word
        string word = sentence.substr(i, SIZE);

        // check if the word has already appeared or is having more
        // than required  repeatitions
        auto it = word_freq.find(word);
        if(it == word_freq.end())
            return false;
        
        if(freq.find(word) == freq.end()) 
            freq.emplace(word, 1);
        else
            ++freq[word];
            
        // check if repeated
        if(freq[word] > word_freq[word])
            return false;
    }

    return true;
}

vector<int> Solution::findSubstring(string str, const vector<string> &words) {
    // mapping of words
    unordered_map<string, int> word_freq;
    for(const auto& word: words) {
        if(word_freq.find(word) == word_freq.end())
            word_freq.emplace(word, 1);
        else
            ++word_freq[word];
    }
    
    const int num_words = words.size();
    const int SIZE = words.front().size();

    vector<int> result;

    // for each index, send the next string matching length of concatenation of words
    for(int i = 0; i + num_words * SIZE - 1< str.size(); i++) {
        if(checkConcatenation(str.substr(i, num_words * SIZE), SIZE, word_freq))
            result.emplace_back(i);
    }

    return result;
}
