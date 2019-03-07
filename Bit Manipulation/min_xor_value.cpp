/*
    Find all unique 4 elements tuple satisfying A[a] + A[b] + A[c] + A[d] = k
    https://www.interviewbit.com/problems/4-sum/

*/

/*
    Solution1 :
        Sort the array.
        Then we fix the two elements from either side, and look for k - sum_pair
        in the ramining sorted array, all the indices satisfying are then checked if 
        they can be part of final result
*/
void findSumPair(vector<int>& arr, int l, int h, int k, int a, int b, set<vector<int>>& s,
                        vector<vector<int>>& result) {
    
    for(int i = l, j = h - 1; i < j; ) {
        // when sum is found
        if(arr[i] + arr[j] == k) {
            vector<int> partial = {arr[a], arr[b], arr[i], arr[j]};
            sort(partial.begin(), partial.end());
            
            if(s.find(partial) == s.end()) {
                result.emplace_back(partial);
                s.emplace(partial);
            }
            ++i, --j;
        }
        else if(arr[i] + arr[j] < k) {
            ++i;
        }
        else {
            --j;
        }
    }
    
}

vector<vector<int> > fourSumSolution2(vector<int> &arr, int k) {
    vector<vector<int>> result;
    set<vector<int>> s;
    
    // sort the given array
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            int curr_sum = arr[i] + arr[j];
            findSumPair(arr, j + 1, arr.size(), k - curr_sum, i, j, s, result);
        }
    }
    sort(result.begin(), result.end());
    
    return result;
}



/*
    Solution 1:
    Sort the array
    A[a] + A[b] + A[c] + A[d] = k, so we loop through
    each pair of elements and check if the other two pairs exists, other pair will be:
    A[a] + A[b] = k - A[c] - A[d]
    While iterating we have A[c] and A[d], we just need index 'a' and 'b'.
    We also store the pair sum value for current pair.
*/
vector<vector<int> > fourSumSolution1(vector<int> &arr, int k) {
    multimap<int, vector<int>> sum_pair;
    vector<vector<int>> result;
    set<vector<int>> s;
    
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            int curr_sum = arr[i] + arr[j];
            // check if a pair exists which satisfies the LHS
            auto res = sum_pair.equal_range(k - curr_sum);
            
            // if atleast a pair is found
            if(res.first != res.second) {
                for(auto it = res.first; it != res.second; it++) {
                    int a = it->second.front();
                    int b = it->second.back();
                    
                    if(b != i && b != j && a != i && a != j) {
                        vector<int> solution = {arr[a], arr[b], arr[i], arr[j]};
                        sort(solution.begin(), solution.end());
                        if(s.find(solution) == s.end()) {
                            result.emplace_back(solution);
                        
                            s.emplace(solution);
                        }   
                    }
                
                }
            }
            // add the current sum pair
            sum_pair.emplace(curr_sum, vector<int>{i, j});
        }
    }
    
    sort(result.begin(), result.end());
    
    return result;
}

vector<vector<int> > Solution::fourSum(vector<int> &arr, int k) {
    return fourSumSolution1(arr, k);
}
