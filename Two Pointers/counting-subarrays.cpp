/*
    https://www.interviewbit.com/problems/counting-subarrays/
    
    Idea is to use sliding window to have a valid window with sum < B.
    
    TC: O(N)
    SC: O(1)
*/
int Solution::solve(vector<int> &arr, int B) {
    int i = 0, j = 0;
    int subarrays = 0, curr_sum = 0;
    
    while(i < arr.size()) {
        // expand the window
        if(curr_sum < B) {
            curr_sum += arr[i++];
        }
        // make the window valid
        while(curr_sum >= B) {
            curr_sum -= arr[j++];
        }
        // add the count of all the subarrays possible in
        // valid window
        int n = i - j;
        // for 'n', total subarrays = n*(n+1)/2, since we are traversing and updating
        // so we can just add 1 + 2 + 3.. n each time adding one term.
        subarrays += n;
    }
    return subarrays;
}
