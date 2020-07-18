/*
    https://www.interviewbit.com/problems/remove-consecutive-characters/
    
    TC: O(N)
    SC: O(1)
*/
string Solution::solve(string s, int B) {
    int i = 0;
    string result;
    
    while(i < s.size()) {
        // traverse all the duplicates of current char
        int j = i;
        while(j < s.size() && s[j] == s[i])
            ++j;
        // check the subarray of current char
        if(j - i < B)
            result = result + s.substr(i, j - i);
        i = j;
    }
    return result;
}
