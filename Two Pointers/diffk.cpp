/*
    find if a(i) + a(j) = k, exists
    https://www.interviewbit.com/problems/diffk/

    TC: O(n)
*/

int Solution::diffPossible(vector<int> &arr, int k) {
    int diff = 0;
    for(int i = 0, j = 1; i < arr.size() && j < arr.size(); ) {
        diff = abs(arr[i] - arr[j]);
        if(diff == k)
            return 1;
        else if(diff > k) {
            ++i;
            if(i == j)
                ++j;
        }
        else {
            ++j;
        }
    }
    
    return 0;
}
