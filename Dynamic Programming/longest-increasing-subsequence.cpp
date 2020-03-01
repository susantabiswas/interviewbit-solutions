/*
    https://www.interviewbit.com/problems/longest-increasing-subsequence/
    
    Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.
*/

// LIS using binary search
// TC: O(nlogn)
int lisBinarySearch(const vector<int>& arr) {
    // for storing the LIS
    vector<int> lis;
    for(const int& num: arr) {
        // check for the first largest number than current
        auto it = lower_bound(lis.begin(), lis.end(), num);
        // if no number is found, then this is the largest, add to LIS
        if(it == lis.end())
            lis.emplace_back(num);
        else {
            // number found, then replace that with this
            // smaller number
            *it = num;
        }
    }
    return lis.size();
}

// LIS using bottom up DP
int lisDP(const vector<int>& arr) {
    const int N = arr.size();
    // dp(i): lis with current element
    vector<int> lis(N, 1);
    int max_lis = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && (lis[j] + 1) > lis[i])
                lis[i] = lis[j] + 1;       
        }
        max_lis = max(max_lis, lis[i]); 
    }
    return max_lis;    
}

int Solution::lis(const vector<int> &arr) {
    //return lisDP(arr);
    return lisBinarySearch(arr);
}
