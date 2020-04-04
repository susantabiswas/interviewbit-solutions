/*
    https://www.interviewbit.com/problems/3-sum-zero/
    
    TC: O(N * N) + O(NlogN) ~ O(N^2)
*/
vector<vector<int> > Solution::threeSum(vector<int> &arr) {
    vector<vector<int>> result;
    if(arr.empty())
        return result;
        
    int i = 0;
    // sort the array
    sort(arr.begin(), arr.end());
    while(i < arr.size() - 1) {
        // a + b + c = 0 => b + c = -a
        // find b and c, also we skip any duplicates
        int left = i + 1, right = arr.size() - 1;
        while(left < right) {
            int target = -arr[i];
            int sum = arr[left] + arr[right];
            
            // triplet found
            if(sum == target) {
                result.emplace_back(vector<int>{arr[i], arr[left], arr[right]});
                ++left, --right;
                // skip the duplicates
                while(arr[left-1] == arr[left])
                    ++left;
                while(arr[right+1] == arr[right])
                    --right;
            }
            else if(sum < target)
                ++left;
            else
                --right;
        }    
        // skip the duplicates
        ++i;
        while(arr[i] == arr[i-1])
            ++i;
    }
    return result;
}
