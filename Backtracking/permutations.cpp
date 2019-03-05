/*
  Find permutations for array elements.
  https://www.interviewbit.com/problems/permutations/
*/

void permutateElements(vector<int>& arr, int curr, vector<int> partial,
                            vector<vector<int>>& result) {
    // all the elements have been arranged
    if(curr == arr.size()) {
        result.emplace_back(partial);
        return;
    }
    
    // starting current index, we add the current element and swap the current element
    // with upcoming elements to get a different order
    for(int i = curr; i < arr.size(); i++) {
        // swap element
        swap(arr[curr], arr[i]);
        partial.emplace_back(arr[curr]);
        permutateElements(arr, curr + 1, partial, result);
        // revert back the swap
        swap(arr[curr], arr[i]);
        partial.pop_back();
    }
    
}

vector<vector<int> > Solution::permute(vector<int> &arr) {
    vector<vector<int>> result;
    vector<int> partial;
    int curr = 0;
    
    permutateElements(arr, curr, partial, result);
    
    return result;
}
