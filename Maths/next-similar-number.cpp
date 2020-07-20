/*
    https://www.interviewbit.com/problems/next-similar-number/
    TC: O(N)
*/
string Solution::solve(string s) {
    // find the first position where i < i+1
    int i = s.size() - 2;
    while(i >= 0 && s[i] >= s[i+1])
        --i;
    
    if(i != -1) {
        // if a pair was found, we check for any digit
        // from back side which is also greater than the first 
        // found instance
        int j = s.size() - 1;
        while(j > i && s[j] <= s[i])
            --j;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
    
        return s;
    }
    return "-1";
}
