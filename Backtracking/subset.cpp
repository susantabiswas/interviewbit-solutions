/*
    https://www.interviewbit.com/problems/subset/
    
    T(n) = T(n-1) + T(n-2) + ... T(0) ............1
    T(n-1) = T(n-2) + T(n-3) + ... T(0) .............2
    
    (1) - (2)
    T(n) - T(n-1) = T(n-1)
    T(n) = 2T(n-1)
    T(n) ~ O(2^N)
*/
void generateSubsets(int curr, vector<int>& arr, 
                    vector<int> partial,
                    vector<vector<int>>& result) {
    // add the subset formed so far
    result.emplace_back(partial);
    
    if(curr < arr.size()) {
        // To get the final subsets in sorted order, we first finish the subsets
        // starting with current number. 
        // The idea is to add the remaning numbers to the current set
        // Curr: [1], rem: [2,3]
        // add with current [1,2 ], [1, 3]
        for(int i = curr; i < arr.size(); i++) {
            // for the current we can either include it or exclude it.
            // include the number
            partial.emplace_back(arr[i]);
            generateSubsets(i + 1, arr, partial, result);
            // exclude the number
            partial.pop_back();
        }
    }
}
        
// TC: O(2^N)           
vector<vector<int> > Solution::subsets(vector<int> &arr) {
    // sort the numbers
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    vector<int> partial;
    
    generateSubsets(0, arr, partial, result);
    return result;
}
