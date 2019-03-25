/*
  https://www.interviewbit.com/problems/justified-text/
*/

vector<string> Solution::fullJustify(vector<string> &arr, int len) {
    int i = 0;
    vector<string> result;
    // empty input
    if(arr.empty())
        return vector<string> {};
        
    while(i < arr.size()) {
        // calculate the number of words that will go in current line
        bool last_line = true;
        int j = len;
        int word_idx = i;
        bool first_word = true;
        
        while(j > 0) {
            // space required for current word including the space preceeding it
            int space_for_word = first_word ? arr[word_idx].size() : arr[word_idx].size() + 1;
            first_word = false;
            if(space_for_word <= j) {
                j = j - space_for_word;
                ++word_idx;
            }    
            else {
                break;
            }
            // check if this is the last line
            if(word_idx >= arr.size()) {
                last_line = true;
                break;
            }
            else
                last_line = false;
        }
        
        // now form the current line
        first_word = true;
        vector<string> temp;
        for(int k = i; k < word_idx; k++) {
            if(k+1 < word_idx)
                temp.emplace_back(arr[k] + ' ');
            else
                temp.emplace_back(arr[k]);
        }
        
        if(!last_line) {
            // put the extra spaces
            for(int i = 0; i < temp.size() && j > 0; i++) {
                // put required space after words
                int req_space = 0;
                if((temp.size() - i - 1) != 0) {
                    req_space = j / (temp.size() - i - 1);
                    if((j % (temp.size() - i - 1)) != 0)
                        req_space += 1;
                }
                
                // incase current line has only one word or last line
                while(req_space--) {
                        temp[i] += ' ';
                        --j;
                }
            }
        }
        while(j > 0) {
            temp.back() += ' ';
            --j;
        }
        
        
        string str;
        for(auto& a: temp) str += a;
        result.emplace_back(str);
        i = word_idx;
    }
    
    return result;
}
