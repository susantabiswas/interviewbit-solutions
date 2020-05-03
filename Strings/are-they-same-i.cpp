/*
    https://www.interviewbit.com/problems/are-they-same-i/?ref=similar_problems
*/
int Solution::solve(const string A, const string B) {
    stack<char> s1, s2;
    string first, second;
    
    // create the first string
    for(const char& c: A) {
        if(c == 'B' && !s1.empty() && s1.top() == '\\') {
            // pop /
            s1.pop();
            // pop the previous char
            if(!s1.empty())
                s1.pop();
        }
        else
            s1.emplace(c);
    }
    while(!s1.empty()) {
        first += s1.top();
        s1.pop();
    }
    
    // create the second string
    for(const char& c: B) {
        if(c == 'B' && !s2.empty() && s2.top() == '\\') {
            s2.pop();
            if(!s2.empty())
                s2.pop();
        }
        else
            s2.emplace(c);
    }
    while(!s2.empty()) {
        second += s2.top();
        s2.pop();
    }
    
    return first == second;
}
