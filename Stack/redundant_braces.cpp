/*
    Remove redundant braces
    https://www.interviewbit.com/problems/redundant-braces/
    TC: O(n)
    SC: O(n)
*/

/*
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
