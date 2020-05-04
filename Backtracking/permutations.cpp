/*
  Find permutations for array elements.
  https://www.interviewbit.com/problems/permutations/
*/

// Solution 1
//TC: O(N^2)
bool nextPermutation(vector<int> &arr) {
    // check if in decreasing order
    // find the first number pair from right, that violates the order
    int i = arr.size() - 2;
    while(i >= 0 && arr[i] >= arr[i+1])
        --i;
    // if array is in decreasing order
    if(i == -1) {
        return false;
    }
    
    // next permutation is possible
    // find the first number which is greater than i-th number
    int j = arr.size() - 1;
    while(j > i && arr[j] <= arr[i])
        --j;
    // [i:j] can be rearranged for generating a bigger number
    // swap the numbers, all the numbers in [i+1:] needs to be reversed
    // so that [i:] makes the smallest arrangement
    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());
    return true;
}


vector<vector<int> > Solution::permute(vector<int> &arr) {
    vector<vector<int>> result;
    
    // sort the array
    sort(begin(arr), end(arr));
    result.emplace_back(arr);
    while(nextPermutation(arr)) {
        result.emplace_back(arr);
    }
    
    return result;
}

////////////////////////////////////////////////////////
// Solution 2
// TC: O(2^N)
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
