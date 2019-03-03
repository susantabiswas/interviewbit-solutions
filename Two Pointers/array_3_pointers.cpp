/*
    https://www.interviewbit.com/problems/array-3-pointers/
*/

/*
    We keep track of each array. We start with the first element of each.
    Compute the required value, now the required value is max of diff, then min of that.
    So we need to make the diff small, which can be done when both the operands are comparable
    so everytime we pick the smallest out of three and increment position in that array.
    We keep track of min value meanwhile.
*/
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int opt_val = numeric_limits<int>::max();
    int curr = numeric_limits<int>::min();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    while(i < A.size() || j < B.size() || k < C.size()) {
        // find the curr value
        curr = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
        opt_val = min(opt_val,  curr);
        
        // increment the array with smallest element
        if(i < A.size())
            pq.emplace(A[i]);
        if(j < B.size())
            pq.emplace(B[j]);
        if(k < C.size())
            pq.emplace(C[k]);
            
        int min_el = pq.top();
        // to ensure that same values don't go again
        while(!pq.empty())
            pq.pop();
        
        if(i < A.size() && min_el == A[i])
            ++i;
        else if(j < B.size() && min_el == B[j])
            ++j;
        else if(k < C.size() && min_el == C[k])
            ++k;
        
    }
    
    return opt_val;
}
