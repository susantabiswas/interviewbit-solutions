/*
    Evaluate reverse polish expression
    https://www.interviewbit.com/problems/evaluate-expression/
    TC: O(n)
*/

int Solution::evalRPN(vector<string> &arr) {
    stack<int> s;
    int num1, num2;

    for(const auto& token: arr) {
        // if it is an operator, pop out last two operand numbers
        if(token == "+" || token == "-" || token == "*" || token == "/") {
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();

            if(token == "+")
                s.emplace(num1 + num2);
            else if(token == "-")
                s.emplace(num1 - num2); 
            else if(token == "*")
                s.emplace(num1 * num2);
            else
                s.emplace(num1 / num2);       
        }
        else {
            // push the number to stack
            s.emplace(stoi(token));
        }
    }
    
    int value = 0;
    if(!s.empty()) {
        value = s.top();
        s.pop();
    }
    return value;
}
