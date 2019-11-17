/*
    Remove redundant braces
    https://www.interviewbit.com/problems/redundant-braces/
    TC: O(n)
    SC: O(n)
*/

/*
    SOLUTION 1
    A brace pair is redundant if it has one or zero operand inside.
    So we start traversing from left and push only opening brace
    or any operator, since the input will be a valid expression
    so any operator encountered will have valid operands also, which
    makes that brace pair to be non redundant.
    If we get a closing brace we check if the stack top is any operator,
    if it is an operator that means that brace pair is not redundant, otherwise
    if opening brace is found as the stack top then it is redundant.
*/
int Solution::braces(string str) {
    stack<char> s;
    
    for(const char& c: str) {
        // when a closing brace is encountered,
        // a brace pair will be redundant if there
        // is one or zero operand inside it.
        // Since we push only operators, so if an operator
        // is encountered that means there are at least two operands
        if(c == ')') {
            if(s.top() == '(')
                return 1;
            while(!s.empty() && s.top() != '(')
                s.pop();
            // pop opening brace
            s.pop();
        }
        // push the opening brace or any operator
        else if(c == '(' || c == '+' || c == '-'
                || c == '*' || c == '/')
            s.emplace(c);
    }
    
    return 0;
}


/*
    SOLUTION 2
    Braces will be redundant when, both the opening and closing brace enclose another open-close pair.
    Also within the braces should lie atleast one operator, otherwise if only tokens are there, it is reduntant to
    have braces.

    So we just need to know what follows each opening brace and what comes before each closing brace.
    So we track whether there was an operator, (, ) last encountered, 
    
    then if we get a right brace:
        if earlier was not ')' or '(': then it contains an expression
            and we remove its opening brace also.
        if earlier was '(', ')':
            check if its opening brace was followed by another brace or not:
                if left was followed by '(': redundant
                else: not redundant and pop that brace
                We use '[' to show that left was followed by a token
    if it is a left brace:
        push it
    if current is an operator:
        means that opening brace has an expression: 
        so change it to '['
*/
int Solution::braces(string str) {
    stack<char> s;
    char prev;
    
    // left braces are represented by ( if they are followed by another (,
    // if they are followed by a token then they are '['
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(')   // left braces
            s.emplace(str[i]);
        else if(str[i] == ')') {  // right brace
            // if the previous char was a token then push its opening brace
            if(prev == '*' || prev == '/' || prev == '+' || prev == '-') {
                s.pop();
            }
            else {  // if previous was also a right brace, check the opening brace
                    // status
                if(s.top() == '(')  // opening brace followed by another left brace
                    return 1;
                else if(s.top() == '[') // opening brace followed by token
                    s.pop();
            }
        }
        else if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-'){  // operator token is encountered, make the last opening brace
                // to '[' to indicate the opening brace contains an expression
            if(s.size() > 0) {
                s.pop();
                s.push('[');
                
            }
        }
        // if current token consitute an expression or a brace
        if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' ||
            str[i] == '(' || str[i] == ')')
        prev = str[i];
    }
    return 0;
}
