/*
    Generate kth row of pascal triangle
    https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/
// TC: O(N), SC: O(N)
vector<int> Solution::getRow(int line) {
    // the terms of a line are the binomial coeff for nth line
    // (n, i), 0 <= i <= n-1, 0 <= n <= line-1, here line is already 0-indexed
    vector<int> result;
    
    // first term
    int term = 1, prev_term = 1;
    result.emplace_back(term);
    
    // line is taken 0-indexed, pos is also 0-indexed
    // (line, pos) = line!/(line - pos)!pos!
    // for 3rd line: 2C0, 2C1, 2C2
    // Also the previous state can be used
    for(int pos = 1; pos <= line; pos++) {
        term = prev_term * (line - (pos - 1)) / pos;
        result.emplace_back(term);
        prev_term = term;
    }
    return result;
}


// TC: O(N), SC: O(N)
vector<int> Solution::getRow(int k) {
    if(k == 0)
        return vector<int>{1};
    vector<int> curr;
    vector<int> prev;
    k = k + 1;
    
    prev.emplace_back(1);
    int n = 1;
    while(n <= k) {
        // push 1 at front and back
        curr.emplace_back(1);
        // generate numbers in between
        for(int i = 1; i < n - 1; i++) {
            curr.emplace_back(prev[i-1] + prev[i]);
        }
        ++n;
        
        // push 1 at back
        curr.emplace_back(1);
        // make the current row as previous row for the next row
        prev = move(curr);
    }
    
    return prev;
}
