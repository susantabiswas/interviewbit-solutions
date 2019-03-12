/*
    Find longest consecutive sequence in an array in O(n)
    https://www.interviewbit.com/problems/longest-consecutive-sequence/
*/

int Solution::longestConsecutive(const vector<int> &arr) {
    unordered_set<int> s;
    int max_len = numeric_limits<int> :: min();
    int curr_len = 0;
    
    for(const auto& a: arr)
        s.emplace(a);
    
    // we find the starting element for a range and from there check 
    // how many consective elements are there
    // Each element is accessed atmost twice. If for a consecutive range
    // only for the first element we will loop, for others loop condition gets false.
    // Similary for non consective elements we run the loop only one for just one element
    for(auto it = s.begin(); it != s.end(); it++) {
        // first element of series
        if(s.find(*it-1) == s.end()) {
            int curr_len = 1;
            // next element
            int next = *it + 1;
            // check how many consecutive elements are there
            while(s.find(next) != s.end()) {
                ++curr_len;
                next += 1;
            }
            
            max_len = max(max_len, curr_len);
        }
    }
    return max_len;
}
