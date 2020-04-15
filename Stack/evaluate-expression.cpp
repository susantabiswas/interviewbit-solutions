/*
   https://www.interviewbit.com/problems/evaluate-expression/
   
   TC: O(N), SC: O(N)
    
*/
int Solution::evalRPN(vector<string> &str) {
    stack<int> operands;
    int value = 0;
    
    for(string& token: str) {
        // if the token is operator then apply on top two 
        // operands else push to operands stack
        if(token == "*" || token == "/" || token == "-" || token == "+") {
            // get the top two operands
            int a = operands.top();
            operands.pop();
            int b = operands.top();
            operands.pop();

            switch(token.front()) {
                case '*':
                    operands.emplace(a*b);
                    break;
                case '/':
                    operands.emplace(b/a);
                    break;
                case '+':
                    operands.emplace(a+b);
                    break;
                case '-':
                    operands.emplace(b-a);
                    break;
            }
        }
        else {
            operands.emplace(stoi(token));
        }
    }
    
    return operands.top();
}
