/*
    Given an array and a sum K, find all combinations of numbers whose sum equals L. There are additional constraints.
    https://www.interviewbit.com/problems/combination-sum-ii/
*/

// SOLUTION 1
// WITHOUT SET
void targetCombinations(int curr, vector<int>& arr, int target,
                        vector<int> partial, vector<vector<int>>& result ) {
    // if target is reached
    if(target == 0) {
        if(target == 0) {
            result.emplace_back(move(partial));
        }
        return;    
    }
    
    for(int i = curr; i < arr.size(); ) {
        partial.emplace_back(arr[i]);
        targetCombinations(i+1, arr, target - arr[i], partial, result);
        partial.pop_back();
        
        ++i;
        while(i < arr.size() && arr[i] == arr[i-1])
            ++i;
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> result;
    sort(begin(arr), end(arr));
    
    targetCombinations(0, arr, target, vector<int>{}, result);
    return result;
}

//////////////////////////////////////////////////////
// SOLUTION 2
void getSumCmbs(int curr, vector<int>& arr, int sum,
                vector<int> partial,
                vector<vector<int>>& result,
                set<vector<int>>& s) {
    // base case
    if(sum <= 0) {
        // add the cmb if the sum equals target
        if(sum == 0 && s.find(partial) == s.end()) {
            s.emplace(partial);
            result.emplace_back(move(partial));
        }
        return;
    }
    
    for(int i = curr; i < arr.size(); i++) {
        // since each number can only be used once.
        partial.emplace_back(arr[i]);
        getSumCmbs(i + 1, arr, sum - arr[i], partial, result, s);    
        partial.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int t) {
    vector<vector<int>> result;
    vector<int> partial;
    set<vector<int>> s;
    // vector of unique numbers
    vector<int> unique_nums;
    
    sort(arr.begin(), arr.end());
         
    getSumCmbs(0, arr, t, partial, result, s);        
    return result;
}


// SOLUTION 3
void findCombinations(vector<int>& arr, int k, vector<int> cmb, int start,
                    vector<vector<int>>& result, set<vector<int>>& cmb_set) {
    if(start > arr.size())
        return;
    if(k == 0) {
        sort(cmb.begin(), cmb.end());
        if(cmb_set.find(cmb) == cmb_set.end()) {
            result.emplace_back(cmb);
            cmb_set.emplace(cmb);
        }
        return;
    }
    
    // since all the numbers are +ve, so getting the
    // sum won't be possible
    if(k < 0)
        return;
    
    
    // exclude adding element
    findCombinations(arr, k, cmb, start + 1, result, cmb_set);
   
    cmb.emplace_back(arr[start]);
    findCombinations(arr, k - arr[start], cmb, start + 1, result, cmb_set);
}
vector<vector<int> > Solution::combinationSum(vector<int> &arr, int k) {
    vector<vector<int>> result;
    vector<int> cmb;
    set<vector<int>> cmb_set;
    findCombinations(arr, k, cmb, 0, result, cmb_set);
    return result;
}
