/*
    https://www.interviewbit.com/problems/convert-to-palindrome/
    
    Start traversal from both sides, we look for the first mismatch and check if getting a palindrome 
    is still possible if exclude either of the mismatching chars and continue
    traversing.
    TC: O(N)
*/
bool isPalin(int start, int end, string& s, int chars_del) {
    // base case
    if(start == end)
        return true;
    if(start == end - 1)
        return s[start] == s[end] || chars_del;
    // when chars are same
    if(s[start] == s[end] && isPalin(start + 1, end - 1, s, chars_del))
        return true;
    // when chars are diff
    if(chars_del) {
        return isPalin(start, end-1, s, chars_del-1) ||
                isPalin(start + 1, end, s, chars_del - 1);
    }
    else
        return false;
}

int Solution::solve(string s) {
    return isPalin(0, s.size()-1, s, 1);
}
