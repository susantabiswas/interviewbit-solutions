/*
    Find k sized subsets for numbers from 1 to N
    https://www.interviewbit.com/problems/combinations/
*/

void findKSubsets(int n, int k, int curr, vector<int> partial, vector<vector<int>>& result) {
    // if k sized subset has been created
    if(curr > n) {
        // subset is added only if it is k sized
        if(partial.size() == k) {
            sort(partial.begin(), partial.end());
            result.emplace_back(partial);
        }
        return;
    }
    
    // exclude current
    findKSubsets(n, k, curr + 1, partial, result);
    
    // include current number
    partial.emplace_back(curr);
    findKSubsets(n, k, curr + 1, partial, result);
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> partial;
    
    // current is the current number in range [1:n]
    int curr = 1;
    findKSubsets(n, k, curr, partial, result);
    sort(result.begin(), result.end());
    
    return result;
}
