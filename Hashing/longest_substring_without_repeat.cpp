/*
    Find the longest window of distinct characters
    https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int Solution::lengthOfLongestSubstring(string str) {
    unordered_map<char, int> h;
    int i = 0, j = 0;
    int max_length = 0;
    int curr_length = 0;
    
    while(i < str.size()) {
        // check if char is there in current window or not
        auto it = h.find(str[i]);
        // if current char is distinct 
        // expand the list
        if(it == h.end()) {
            // check if max length
            ++curr_length;
            
            if(curr_length > max_length) {
                max_length = curr_length;
            }
            
            h.emplace(str[i], 1);
            ++i;
        }   
        // now shrink window till first occurence of str[i] is removed
        else {  // if current char is a duplicate
                // start shrinking the subset
            h.erase(str[j]);
            --curr_length;
            ++j;
        }
    }
    
    return max_length;
}
