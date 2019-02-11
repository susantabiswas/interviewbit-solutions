/*
    Convert string A to B in min no. of edits.
    https://www.interviewbit.com/problems/edit-distance/
*/

int levenshteinDistance(string a, int a_idx, string b, int b_idx,
                    vector<vector<int>>& cache) {
    // if 'a' has ended, remaining 'b' chars are to be inserted
    if(a_idx < 0 && b_idx >= 0)
        return b_idx + 1;
    // if 'b' has ended, remaining 'a' chars are to be deleted
    if(b_idx < 0 && a_idx >= 0)
        return a_idx + 1;
    if(a_idx < 0 && b_idx < 0)
        return 0;
        
    // if the current chars are same
    if(a[a_idx] == b[b_idx]) 
        return cache[a_idx][b_idx] = levenshteinDistance(a, a_idx - 1, b, b_idx - 1, cache);
    
    // when chars are diff
    if(cache[a_idx][b_idx] == 0) {
        cache[a_idx][b_idx] = 1 + min({
            levenshteinDistance(a, a_idx - 1, b, b_idx - 1, cache), //substitution
            levenshteinDistance(a, a_idx, b, b_idx - 1, cache), // deletion
            levenshteinDistance(a, a_idx - 1, b, b_idx, cache)  // insertion
        });
    }
    
    return cache[a_idx][b_idx];
}

int Solution::minDistance(string a, string b) {
    // each entry (i,j) is min num of operations till those indices 
    vector<vector<int>> cache(a.size(), vector<int>(b.size(), 0));
    return levenshteinDistance(a, a.size()-1, b, b.size()-1, cache);
}
