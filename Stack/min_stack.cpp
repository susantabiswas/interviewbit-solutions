/*  Min stack class
    https://www.interviewbit.com/problems/min-stack/
*/

stack<int> min_stack;
stack<int> s;

MinStack::MinStack() {
    while(!s.empty())
        s.pop();
    while(!min_stack.empty())
        min_stack.pop();
}

void MinStack::push(int x) {
    s.push(x);
    // push an element in min_stack only if it is empty or
    // when all the elements below it greater
    if(min_stack.empty() || min_stack.top() >= x) {
        min_stack.push(x);
    }
}

void MinStack::pop() {
    if(!s.empty()) {
        // remove current element and check
        // if it needs to be removed from min_stack also
        int el = s.top();
        s.pop();
        
        if(min_stack.top() == el) 
            min_stack.pop();
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
        
    return s.top();
}

int MinStack::getMin() {
    if(min_stack.empty())
        return -1;
    return min_stack.top();
}

