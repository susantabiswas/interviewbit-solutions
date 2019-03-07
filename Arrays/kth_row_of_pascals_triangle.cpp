/*
    Generate kth row of pascal triangle
    https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

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
