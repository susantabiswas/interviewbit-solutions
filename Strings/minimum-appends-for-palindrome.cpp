/*
    Since the chars can be inserted at back only, we need to find the
    length of the longest palindrome which ends at the last char. All the chars
    before the starting of that palindrome will be inserted at the back.
    
    To do this, we use LPS like method, where we find the substring that matches the suffix in
    reverse order.
    In the end we check the length of the longest palindrome ending at the last char, 
    remaining chars needs to be inserted.
    TC: O(N)
*/
int Solution::solve(string s) {
    const int N = s.size();
    // palindromic_suffix(i): no. of matching chars from backside till  
    // ith index
    vector<int> palindromic_suffix(N, 0);
    int i = 0, j = N - 1;
    
    // we compare the string positions from starting and reference 
    // pos j from back
    while(i < N) {
        if(s[i] == s[j]) {
            // No. of chars of palindrome ending at i
            // which matches the suffix in reverse order
            palindromic_suffix[i] = N - j;
            ++i, --j;    
        }
        else {
            if(j == N-1)
                ++i;
            else
                // if the current char, doesnt match
                // check the char to fall back to in the suffix string
                j = N - 1 - palindromic_suffix[j+1];
        }
    }
    return N - palindromic_suffix[N-1];
}
