/*
    https://www.interviewbit.com/problems/minimum-parantheses/
    
    Idea is to take out the balanced set of braces from consideration
    and count the unbalanced left and right braces.
*/

int Solution::solve(string str) {
    int left = 0, unbalanced_right = 0;
    // we remove the balanced braces
    stack<char> s;
    for(const char& c: str) {
        if(c == '(')
            s.emplace(c);
        else {
            // if there is no ( to balance the right
            if(s.empty())
                ++unbalanced_right;
            else
                s.pop();
        }
        
    }
    // unbalanced left braces will be left in stack
    return unbalanced_right + s.size();
}
