/*
  Find first missing int
  https://www.interviewbit.com/problems/first-missing-integer/
  TC: O(nlogn)
*/
int Solution::firstMissingPositive(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    int missing = 1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0 && arr[i] == missing)
            ++missing;
    }
    return missing;
}
