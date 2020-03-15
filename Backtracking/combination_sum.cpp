/*
    For a given target find all combinations of array numbers whose sum equals it.
    https://www.interviewbit.com/problems/combination-sum/
*/

// SOLUTION 1
/*
    https://www.interviewbit.com/problems/combination-sum/
    TC: O(2^N)
*/

void findCmbSum(int curr, vector<int>& arr,
                int sum, vector<int> partial,
                vector<vector<int>>& result) {
    
    // when sum if achieved or all the numbers have been traversed
    if(sum <= 0 || curr == arr.size()) {
        if(sum == 0) {
            result.emplace_back(move(partial));
        }
        return;
    }
    
    for(int i = curr; i < arr.size(); i++) {
        partial.emplace_back(arr[i]);
        // for the next recursive call, the sent index is the current one
        // so that we have the choice of using or not using it
        findCmbSum(i, arr, sum - arr[i], partial, result);
        partial.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int t) {
    vector<vector<int>> result;
    vector<int> partial;
    vector<int> unique_nums;
    sort(arr.begin(), arr.end());
    
    // since a number can be used multiple times anyways, this makes the 
    // usage of duplicate numbers redundant
    for(int i = 0; i < arr.size(); i++)
        if(i == 0 || arr[i] != arr[i-1]) 
            unique_nums.emplace_back(arr[i]);
            
    findCmbSum(0, unique_nums, t, partial, result);
    return result;
}


// SOLUTION 2
void findSumCombinations(vector<int>& arr, int k, int curr, int sum, vector<int> partial, 
                        set<vector<int>>& s, vector<vector<int>>& result) {
    
    
    // if the partial sum has exceeded target, 
    if(sum > k) 
        return;
    // if combination sum is equal to target
    if(sum == k) {
        sort(partial.begin(), partial.end());
        // add only if it is already not there
        if(s.find(partial) == s.end()) {
            result.emplace_back(partial);
            // add to set
            s.emplace(partial);
        }
        return;
    }
    
    // if all the array elements have been tried
    if(curr == arr.size())
        return;
        
    // we can do three things: exclude current number, repeat current number or
    // add current and go to next number
    findSumCombinations(arr, k, curr + 1, sum, partial, s, result);
    
    partial.emplace_back(arr[curr]);
    // add current and again repeat in next step
    findSumCombinations(arr, k, curr, sum + arr[curr], partial, s, result);
    findSumCombinations(arr, k, curr + 1, sum + arr[curr], partial, s, result);
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &arr, int k) {
    vector<vector<int>> result;
    vector<int> partial;
    set<vector<int>> s;
    int curr = 0;
    long sum = 0;
    
    findSumCombinations(arr, k, curr, sum, partial, s, result);
    
    sort(result.begin(), result.end());
    return result;
}
