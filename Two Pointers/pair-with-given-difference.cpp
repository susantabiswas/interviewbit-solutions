/*
    https://www.interviewbit.com/problems/pair-with-given-difference/
*/

// TC: O(N), SC: O(N)
int sol1(vector<int> &arr, int B)  {
    unordered_set<int> visited;
    
    for(const int &el: arr) {
        // Assume current element as A and C at a time respectively in
        // eq A - C = B
        if(visited.count(-1 * (B - el)) ||
            visited.count(B + el))
            return 1;
        visited.emplace(el);
    }
    return 0;
}

int Solution::solve(vector<int> &arr, int B) {
    return sol1(arr, B);
}
