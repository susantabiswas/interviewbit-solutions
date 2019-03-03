/* 
    Find the nearest smaller element on left
    https://www.interviewbit.com/problems/nearest-smaller-element/

    TC: O(n)
    SC: O(n)
*/

/*
    We use a stack which has the smallest element at top, Since we want the nearest element
    if current element is smaller than top then keep popping elements till top is bigger or stack is 
    empty. 
*/
vector<int> Solution::prevSmaller(vector<int> &arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);
    
    for(int i = 0; i < arr.size(); i++) {
        while(!s.empty() && s.top() >= arr[i])
            s.pop();
        
        if(!s.empty())
            result[i] = s.top();
        s.emplace(arr[i]);
    }
    
    return result;
}
