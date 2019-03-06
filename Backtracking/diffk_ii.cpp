/*
    Find numbers such that A[i] - A[j] = k, i != j
    https://www.interviewbit.com/problems/diffk-ii/
*/

int Solution::diffPossible(const vector<int> &A, int k) {
    // Solution 1
    /*vector<int> arr(A.begin(), A.end());
    sort(arr.begin(), arr.end());
    
    int diff = 0;
    for(int i = 0, j = 1; j < arr.size() && i < j; ) {
        diff = arr[j] - arr[i];
        if(diff == k)
            return 1;
        else if(diff < k)
            ++j;
        else
            ++i;
    }*/
    
    // Solution 2
    // We store the values in a set, after that we start the traversal. Now a number can be A_i or A_j, 
    // we don't know what that is so, we we search for both:
    // if the number is A_j: => A_i = k + num
    // if the number is A_i: => A_j =  k - num
    set<int> other_number;
    
    for(int i = 0; i < A.size(); i++) {
        if(other_number.find(A[i] + k) != other_number.end() || 
                other_number.find(A[i] - k) != other_number.end())
            return 1;
        other_number.emplace(A[i]);
    }
    return 0;
}
