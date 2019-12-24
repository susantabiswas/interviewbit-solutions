/*
    For an array A, find the maximum of j - i, constrainted to A[i] <= A[j]
    https://www.interviewbit.com/problems/max-distance/
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.empty())
        return -1;
        
    // sort the array based on values
    vector<pair<int, int>> arr;
    for(int  i= 0; i < A.size(); i++) {
        arr.emplace_back(make_pair(A[i], i));
    }
    // sort the array by the value 
    sort(begin(arr), end(arr), [](pair<int,int> a, pair<int,int> b)->bool{
        return a.first < b.first;
    });

    // now the job is to find the max (j - i), since Ai <= Aj can be
    // ensured more easily as it is sorted, for any 'i' all on its right are 
    // candidates
    // we start tracking max index in [i:N] from back for 'ith' index
    int max_diff = 0;
    // max index for last element is itself
    int max_so_far = arr.back().second;
    // now find the max (j - i) distance using the max_index array
    for(int i = arr.size()-1; i >= 0; i--) {
        max_so_far = max(max_so_far, arr[i].second);
        // check if diff of (i - max_j_after_i) is max
        max_diff = max(max_diff, max_so_far - arr[i].second);
    }
    return max_diff;
}
