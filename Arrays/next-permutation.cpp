/*
    https://www.interviewbit.com/problems/next-permutation/
*/
vector<int> Solution::nextPermutation(vector<int> &arr) {
    // check if in decreasing order
    // find the first number pair from right, that violates the order
    int i = arr.size() - 2;
    while(i >= 0 && arr[i] >= arr[i+1])
        --i;
    // if array is in decreasing order
    if(i == -1) {
        // return the smallest arrangement
        sort(arr.begin(), arr.end());
        return arr;
    }
    
    // next permutation is possible
    // find the first number which is greater than i-th number
    int j = arr.size() - 1;
    while(j > i && arr[j] <= arr[i])
        --j;
    // [i:j] can be rearranged for generating a bigger number
    // swap the numbers, all the numbers in [i+1:] needs to be reversed
    // so that [i:] makes the smallest arrangement
    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}
