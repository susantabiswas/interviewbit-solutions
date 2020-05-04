/*
    generate all unique subsets
    https://www.interviewbit.com/problems/subsets-ii/
    
    When there are duplicates, then the problem is we can have single element subsets of same thing.
    Eg: [2, 2, 2] , tthen [2], [2] will be created when 2nd and 3rd elements are the only elements in subset.
*/

/// SOLUTION 1
void generateUniqueSubsets(int curr, vector<int>& arr,
                    vector<int> partial, vector<vector<int>>& result) {
    //add the subset
    result.emplace_back(partial);
    
    if(curr < arr.size()) {
        for(int i = curr; i < arr.size(); ) {
            partial.emplace_back(arr[i]);
            generateUniqueSubsets(i+1, arr, partial, result);
            partial.pop_back();
            
            ++i;
            // skip the duplicates
            while(i < arr.size() && arr[i] == arr[i-1])
                ++i;
        }
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &arr) {
    // sort the numbers
    sort(begin(arr), end(arr));
    vector<vector<int>> result;
    
    generateUniqueSubsets(0, arr, vector<int>{}, result);
    return result;
}

///////////////////////////////////////////////////////////////////
// SOLUTION 2
// generates subsets
void generateSubsets(int curr, vector<int>& arr, 
                    vector<int> partial, set<vector<int>>& unique_sets,
                    vector<vector<int>>& result) {
    // all the array elements have been traversed and the current set is unique
    if(curr == arr.size()) {
        if (unique_sets.find(partial) == unique_sets.end()) {
            // add to set
            result.emplace_back(partial);
            unique_sets.emplace(move(partial));
        }
        return;
    }          
    
    // exclude the current number
    generateSubsets(curr + 1, arr, partial, unique_sets, result);
    // add the current number
    partial.emplace_back(arr[curr]);
    generateSubsets(curr + 1, arr, partial, unique_sets, result);
}
       
// TC: O(2^N * N), O(N) for copying the vector to result             
vector<vector<int> > Solution::subsetsWithDup(vector<int> &arr) {
    vector<vector<int>> result;
    // sort the array so that the duplicate comb can be avoided
    sort(arr.begin(), arr.end());
    vector<int> partial;
    set<vector<int>> unique_sets;
    
    generateSubsets(0, arr, partial, unique_sets, result);
    sort(result.begin(), result.end());
    return result;
}
