/* 
    merge two sorted arrays

    TC: O(n + m)
    https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
 */

// Type 1
// TC: O(m + n)
void Solution::merge(vector<int> &A, vector<int> &B) {
    const int M = A.size(), N = B.size();
    // Now the initial values of A is in the begining, so 
    // start merging from back side
    int a = M - 1, b = N - 1; 
    // expand the size of A
    A.resize(M + N);
    int write_idx = A.size() - 1;
    
    while(a >= 0 && b >= 0) {
        A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
    }
    while(a >= 0)
        A[write_idx--] = A[a--];
    while(b >= 0)
        A[write_idx--] = B[b--];
}

// Type 2
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
