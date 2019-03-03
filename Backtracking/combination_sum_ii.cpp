/*
    Given an array and a sum K, find all combinations of numbers whose sum equals L. There are additional constraints.
    https://www.interviewbit.com/problems/combination-sum-ii/
*/

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
