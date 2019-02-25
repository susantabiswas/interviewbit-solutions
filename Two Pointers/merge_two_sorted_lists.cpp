/* 
    merge two sorted arrays

    TC: O(n + m)
    https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
 */

void Solution::merge(vector<int> &a, vector<int> &b) {
    vector<int> result;
    
    int a_curr = 0, b_curr = 0;
    // start traversal, each time writing element which is smaller
    while(a_curr < a.size() && b_curr < b.size()) {
        if(a[a_curr] < b[b_curr])
            result.emplace_back(a[a_curr++]);
        else if(b[b_curr] < a[a_curr])
            result.emplace_back(b[b_curr++]);
        else
            result.emplace_back(a[a_curr++]);
    }
    
    // if any of the arrays has some elements left
    while(a_curr < a.size())
        result.emplace_back(a[a_curr++]);
    while(b_curr < b.size())
        result.emplace_back(b[b_curr++]);
    
    a_curr = 0;
    bool new_entries = false;
    
    // copy bakc elements to 'a' array
    for(int i = 0; i < result.size(); i++) {
        if(!new_entries && a_curr < a.size()) {
            a[a_curr++] = result[i];
        }
        else {
            new_entries = true;
            a.emplace_back(result[i]);
        }
    }
}
