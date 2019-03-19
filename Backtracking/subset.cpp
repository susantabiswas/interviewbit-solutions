/*
  Find all unique subsets
  https://www.interviewbit.com/problems/subset/
*/
void findSubsets(int curr, vector<int>& arr, vector<vector<int> >& result, 
                        vector<int> partial, set<vector<int> >& s) {
    // when all the elements have been traversed
    if(curr == arr.size()) {
        // arrange in increasing order
        sort(partial.begin(), partial.end());
        if(s.find(partial) == s.end()) {
            s.emplace(partial);
            result.emplace_back(partial);
        }
        return;
    }
    
    // for the current element, either we can include or exclude it
    findSubsets(curr + 1, arr, result, partial, s);
    partial.emplace_back(arr[curr]);
    findSubsets(curr + 1, arr, result, partial, s);
}

vector<vector<int> > Solution::subsets(vector<int> &arr) {
    vector<vector<int> > result;
    vector<int> partial;
    set<vector<int> > s;
    
    findSubsets(0, arr, result, partial, s);
    sort(result.begin(), result.end());
    return result;
}
