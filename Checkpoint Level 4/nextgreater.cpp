/*
    Find the next greatest element on right side
    https://www.interviewbit.com/problems/nextgreater/

    TC: O(n)
    SC: O(n)
*/

/*
    Since we just want the nearest greater, so start traversal from right
    and we maintain a stack. If stack is empty means all on right are smmaller
    else check if stack top is smaller or greater. Since we want greater, so pop
    elements till there is a greater element, those elements which were removed 
    were smaller than current, and current will be closer for the coming elements
    anyways.
    
    TC: O(n)
    SC: O(n)
*/
vector<int> Solution::nextGreater(vector<int> &arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;
    
    for(int i = arr.size() - 1; i >= 0; i--) {
        // check if there is any element greater than current
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        if(!s.empty())
            result[i] = s.top();
        // add current to stack
        s.emplace(arr[i]);
    }
    
    return result;
}
