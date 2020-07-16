/*
    https://www.interviewbit.com/problems/merge-k-sorted-arrays/
    
    TC: O(nlogM)
*/

struct VectorIterator {
    vector<int>::const_iterator curr;
    vector<int>::const_iterator last;
};

vector<int> Solution::solve(vector<vector<int> > &arr) {
    const int M = arr.size();
    vector<int> result;
    
    priority_queue<VectorIterator, vector<VectorIterator>, 
                function<bool(VectorIterator, VectorIterator)>>
        min_heap([](const VectorIterator& a, const VectorIterator& b)->bool {
            return *(a.curr) > *(b.curr);
        });
    // add the first element from each array
    for(auto &nums: arr)
        if(!nums.empty())
            min_heap.emplace(VectorIterator{nums.cbegin(), nums.cend()});
    
    while(!min_heap.empty()) {
        auto it = min_heap.top();
        min_heap.pop();
        result.emplace_back(*(it.curr));
        ++it.curr;
        if(it.curr != it.last)
            min_heap.emplace(it);
    }
    return result;
}
