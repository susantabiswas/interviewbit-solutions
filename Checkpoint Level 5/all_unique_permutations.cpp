/*
    Generate permutation of array elements
    https://www.interviewbit.com/problems/all-unique-permutations/
*/

void permutateElements(vector<int>& arr, int curr, vector<int> partial,
                            vector<vector<int>>& result, set<vector<int>>& s) {
    // all the elements have been arranged
    if(curr == arr.size()) {
        if(s.find(partial) == s.end()) {
            result.emplace_back(partial);
            s.emplace(partial);
        }
        return;
    }
    
    // starting current index, we add the current element and swap the current element
    // with upcoming elements to get a different order
    for(int i = curr; i < arr.size(); i++) {
        // swap element
        swap(arr[curr], arr[i]);
        partial.emplace_back(arr[curr]);
        permutateElements(arr, curr + 1, partial, result,s );
        // revert back the swap
        swap(arr[curr], arr[i]);
        partial.pop_back();
    }
    
}

vector<vector<int> > Solution::permute(vector<int> &arr) {
    vector<vector<int>> result;
    vector<int> partial;
    set<vector<int>> s;
    int curr = 0;
    
    permutateElements(arr, curr, partial, result, s);
    
    return result;
}
