/*
    https://www.interviewbit.com/problems/balanced-parantheses/
    
    Sol1: Using stack
    
*/

// Sol1: Using stack
int sol1(string& str) {
    stack<char> s;
    for(char& c: str) {
        if(c == ')') {
            if(s.empty())
                return 0;
            s.pop();
        }
        if(c == '(')
            s.emplace(c);
    }
    return s.empty();
}

// Sol2: O(1) space
int sol2(string& str) {
    int left = 0;
    for(char &c: str) {
        if(c == ')') {
            if(left == 0)
                return 0;
            --left;
        }
        else if(c == '(')
            ++left;
    }
    return left == 0;
}

int Solution::solve(string str) {
    // return sol1(str);
    return sol2(str);
}
