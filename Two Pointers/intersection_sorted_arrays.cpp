/*
    Intersection of two arrays
    https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
    TC: O(n)
*/

vector<int> Solution::intersect(const vector<int> &a, const vector<int> &b) {
    vector<int> result;
    int a_start = 0, b_start = 0, a_end = a.size(), b_end = b.size();
    
    while(a_start < a_end && b_start < b_end) {
        // if same number
        if(a[a_start] == b[b_start]) {
            result.emplace_back(a[a_start]);
            ++a_start, ++b_start;
        }
        else if(a[a_start] < b[b_start])
            ++a_start;
        else
            ++b_start;
    }
    return result;
}
