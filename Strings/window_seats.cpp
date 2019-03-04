string Solution::minWindow(string a, string b) {
    // take frequency count of string b
    unordered_map<char, int> b_freq;
    for(const char& c: b)
        if(b_freq.find(c) == b_freq.end())
            b_freq.emplace(c, 1);
        else
            ++b_freq[c];
            
    // now take frequency count of string 'a'
    unordered_map<char, int> a_freq;
    int i = 0;
    for(i = 0; i < a.size(); i++)
        // add only the characters present in string b
        if(b_freq.find(a[i]) != b_freq.end()) {
            if(a_freq.find(a[i]) == a_freq.end())
                a_freq.emplace(a[i], 1);
            else 
                ++a_freq[a[i]];
        }
    
    
    int start = 0, end = a.size() - 1;
    bool window_resized = false;
    while(start <= end) {
        // we try reducing window size till the min freq for each req char is maintained
        window_resized = false;
        // try reducing end index
        // when current char is part of 'b' charset
        if(b_freq.find(a[end]) != b_freq.end()) {
            // check if freq of current can be reduced or not by ignoring this char
            if(a_freq[a[end]] - 1 >= b_freq[a[end]]) {
                --end;
                --a_freq[a[end]];
                window_resized = true;
            }
        }
        else {// char not part of string b
            --end;
            window_resized = true;
        }
        
        // try reducing window size from front
        if(b_freq.find(a[start]) != b_freq.end()) {
            // check if freq of current can be reduced or not by ignoring this char
            if(a_freq[a[start]] - 1 >= b_freq[a[start]]) {
                ++start;
                --a_freq[a[start]];
                window_resized = true;
            }
        }
        else {// char not part of string b
            start;
            window_resized = true;
        }
        
        if(window_resized == false)
            break;
    }
    
    // check if the freq count of b chars is satisfied in a window
    for(const auto& it: a_freq) {
        if(it.second < b_freq[it.first])
            return "";
    }
    
    string min_window = a.substr(start, start + end);
    return min_window;
}
