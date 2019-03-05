/*
    generate all unique subsets
    https://www.interviewbit.com/problems/subsets-ii/
*/

void findSubsets(vector<int>& arr, int curr, vector<int> partial,
                        vector<vector<int>>& result, set<vector<int>>& s) {
    if(curr > arr.size())
        return;
    // check if subset has already been added or not
    if(curr == arr.size()) {
       // sort(partial.begin(), partial.end());
        if(s.find(partial) == s.end()) {
            s.emplace(partial);
            result.emplace_back(partial);
        }
        return;
    }
    // each time we can either include or exclude the current element
    findSubsets(arr, curr + 1, partial, result, s);
    
    partial.emplace_back(arr[curr]);
    findSubsets(arr, curr + 1, partial, result, s);
    return;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &arr) {
    int curr = 0;
    sort(arr.begin(), arr.end());
 
    vector<int> partial;    
    vector<vector<int>> result;
    set<vector<int>> s;
    
    findSubsets(arr, curr, partial, result, s);
    sort(result.begin(), result.end());
    return result;
}
