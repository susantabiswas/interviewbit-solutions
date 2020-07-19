/*
    https://www.interviewbit.com/problems/leaders-in-an-array/
    
    TC: O(N)
*/
vector<int> Solution::solve(vector<int> &arr) {
    if(arr.empty())
        return vector<int>{};
        
    vector<int> result;
    result.emplace_back(arr.back());
    int max_right = arr.back();
    
    for(int i = arr.size() - 2; i >= 0; i--) {
        if(arr[i] > max_right)
            result.emplace_back(arr[i]);
        max_right = max(max_right, arr[i]);
    }
    return result;
}
