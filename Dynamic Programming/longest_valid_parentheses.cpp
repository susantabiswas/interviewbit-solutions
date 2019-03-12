/*
  Find the longest sequence of valid parentheses pairs.
  https://www.interviewbit.com/problems/longest-valid-parentheses/
*/

/*
    For each matching bracket par, we make its index 1, then after doing one complete
    scan, we see the largest continous series of 1s. That is the required length
*/
int Solution::longestValidParentheses(string str) {
    stack<int> s;
    vector<int> dp(str.size(), 0);
    int start = -1;
    
    for(int i = 0; i < str.size(); i++) {
        // opening brace
        if(str[i] == '(') {
            s.emplace(i);
        }
        // closing brace
        else if(str[i] == ')') {
            // if there is an opening brace for this
            if(!s.empty()) {
                dp[s.top()] = 1;
                s.pop();
                dp[i] = 1;
            }
        }
    }
    
    // scan for continous 1s
    int brace_length = 0;
    int max_length = 0;
    for(int i = 0; i < dp.size(); i++) {
        if(dp[i] == 1) {
            if((i-1) >= 0 && dp[i-1] == 1) {
                ++brace_length;
            }
            else
                brace_length = 1;
        }
        else {
            brace_length = 0;
        }
        
        max_length = max(max_length, brace_length);
    }
    
    return max_length;
}
