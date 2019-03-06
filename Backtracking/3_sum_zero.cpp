/*
  Find all three elements whose sum is 0.
  https://www.interviewbit.com/problems/3-sum-zero/
*/

// for a given target, finds two elements whose sum is equal to target
void twoSum(vector<int>& arr, int k, int idx, 
                vector<vector<int>>& result, set<vector<int>>& s) {
    
    for(int i = 0, j = arr.size() - 1; i < j; ) {
        // if the pair sum is equal to target
        if(arr[i] + arr[j] == k) {
            // check if the two elements are not the same as target
            if(i != idx && j != idx) {
                vector<int> partial;
                
                partial.emplace_back(arr[i]);
                partial.emplace_back(arr[j]);
                partial.emplace_back(-k);
                //sort the tuplet
                sort(partial.begin(), partial.end());
                
                if(s.find(partial) == s.end()) {
                    result.emplace_back(partial);
                    s.emplace(partial);
                }
            }
            ++i, --j;
        }     
        else if(arr[i] + arr[j] < k) 
            ++i;
        else
            --j;
            
    }
}

vector<vector<int> > Solution::threeSum(vector<int> &arr) {
    // sort the elements 
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    set<vector<int>> s;
    
    // for each element, check if there are two other elements whose
    // sum is equal to current element so that total sum is 0.
    for(int i = 0; i < arr.size(); i++) {
        twoSum(arr, -1 * arr[i], i, result, s);
    }
    
    return result;
}
