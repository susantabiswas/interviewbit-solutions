/*
    https://www.interviewbit.com/problems/k-largest-elements/
*/

vector<int> Solution::solve(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    
    for(auto &el: arr) {
        min_heap.emplace(el);
        if(min_heap.size() > k)
            min_heap.pop();
    }
    vector<int> result;
    while(!min_heap.empty()) {
        result.emplace_back(min_heap.top());
        min_heap.pop();
    }
    return result;
}
