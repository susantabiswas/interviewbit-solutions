/*  We use sliding window to solve the problem.
    TC: O(n)
    https://www.interviewbit.com/problems/window-string/
*/

string Solution::minWindow(string a, string b) {
    if(b.empty())
        return "";
    
    // create hash table for character frequency
    unordered_map<char, int> freq;
    int req_chars = 0;
    for(const char& c: b) {
        if(freq.find(c) == freq.end())
            freq[c] = 1;
        else
            freq[c] += 1;
        ++req_chars;
    }
    
    string min_str;
    int i = 0, j = 0;
    while(i < a.size()) {
        // expand the window till all the chars are covered
        if(req_chars > 0) {
            // char is found
            auto it = freq.find(a[i]);
            if(it != freq.end()) {
                // required char count is decreased only if 
                // current char is not an extra char
                if(it->second > 0)
                    --req_chars;
                // decrease current char frequency
                --(it->second);
            }
            ++i;
        }    
        
        // shrink the window till the condition becomes invalid
        while(req_chars == 0) {
            // update max length substring
            if((i - j) < min_str.size() || min_str.empty()) {
                min_str = a.substr(j, i - j);
            }
            auto it = freq.find(a[j]);
            if(it != freq.end()) {
                // current char only becomes necessary if 
                // this is not an extra, for an extra char
                // its freq count will be negative
                if(it->second >= 0)
                    ++req_chars;
                ++(it->second);
            }
            ++j;
        }
    }
    
    return min_str;
}
