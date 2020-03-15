/*
    https://www.interviewbit.com/problems/combinations/
    
    TC: O(2^N), worst case: when it exlcudes numbers and reach N
    
    The idea is similar to generate Subset problem. Since the range is already known
    so no need to sort the numbers as well as we will be going from 1, 2....N.
    
    Every time two options are there: include or exclude current number.
    To get the final subsets in sorted order it is important to first do recursion 
    when the current number is included, this makes sure that smaller gets included first.
    
    eg: [1, 2]
    When included first: [1], [2]
    [1] is creatd before [2]
*/

void generateKCmbs(int curr, int n, int k,
                    vector<int> partial,
                    vector<vector<int>>& result) {
    // when k numbers have been traversed
    if(partial.size() == k || curr > n) {
        if(partial.size() == k)
            result.emplace_back(move(partial));
        return;
    }
    
    // include current number, to get the smaller number subsets before larger num subsets
    partial.emplace_back(curr);
    generateKCmbs(curr + 1, n, k, partial, result);
    
    // exclude current number
    partial.pop_back();
    generateKCmbs(curr + 1, n, k, partial, result);
}
                    
vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> partial;
    vector<vector<int>> result;
    
    generateKCmbs(1, n, k, partial, result);
    return result;
}
