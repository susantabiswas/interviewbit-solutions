/* 
    Find max in k sized window
    https://www.interviewbit.com/problems/sliding-window-maximum/

    Solution 2:
        TC: O(n)
        SC: O(k)
    
    Solution 1:
     TC: O((n-k)logk)
     SC: O(k)
 */
struct comp {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }    
};

/*
    We use a BST which can have duplicates also, then every time 
    we find the max in O(logk) time,
    TC: O((n-k)logk)
*/
vector<int> solution1(vector<int>& arr, int k) {
    multiset<int, comp> ms;
    
    vector<int> result;
    
    // populate the heap with k elements first
    for(int i = 0; i < k; i++) {
        ms.emplace(arr[i]);
    }
    
    for(int i = 0; i <= arr.size() - k; i++) {
        result.emplace_back(*(ms.begin()));
        
        // remove the first element of current window
        auto it = ms.find(arr[i]);
        ms.erase(it);
        // add the first element of next window
        if((i + k) < arr.size()) {
            ms.emplace(arr[i+k]);
        }
    }
    
    return result;
}

// solution 2
/*
    We use a deque to keep track of current max in current window.
    The front of deque always contains the max element, so for each
    window when we are adding elements, we keep popping elements from queue
    back till all the elements before current are greater.
    
    For each window, after setting the max, we check if the current front
    of deque is part of next window or not, if it is not then pop
    
    TC: O(n), since each is pushed and popped only once
    SC: O(k)
*/
vector<int> solution2(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> q;
    
    // populate the first window
    for(int i = 0; i < k; i++) {
        // make sure all the elements before current are greater
        while(!q.empty() && arr[q.back()] < arr[i])
            q.pop_back();
        // push current element
        q.emplace_back(i);    
    };
    
    // find max for rest of the windows
    for(int i = 0; i <= arr.size() - k; i++) {
        // max for current window
        result.emplace_back(arr[q.front()]);
        
        // remove first element of current window
        if(q.front() <= i)
            q.pop_front();
        // add first element of next window
        while(!q.empty() && arr[q.back()] < arr[i + k])
            q.pop_back();
        // push current element
        q.emplace_back(i + k);
    }
    
    return result;    
}

vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    // solution 1
    // return solution1(arr, k);
    
    return solution2(arr, k);
}