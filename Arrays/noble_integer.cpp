/*
    Given an integer array, find if an integer number exists in the array such that the 
    number of integers greater than that in the array equals to it
    https://www.interviewbit.com/problems/noble-integer/
*/

// Solution 1 
int Solution::solve(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    int i = arr.size() - 1;
    const int N = arr.size();
    while(i >= 0) {
        // find the number of greater numbers
        int greater_left = N - i - 1;
        // if condition is met
        if(arr[i] == greater_left)
            return 1;
        
        // now we need to go to next unique number
        int curr = arr[i];
        --i;
        // traverse till a different number is reached, this is
        // done due to duplicates
        while(i >= 0 && arr[i] == curr)
            --i;
    }
    
    return -1;
}

// Solution 2
int Solution::solve(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size(); i++) {
        // skip duplicates and go to last instance of duplicate
        // so that it can be said for sure that remaining elements
        // are greater
        while((i+1) < arr.size() && arr[i+1] == arr[i])
            ++i;
        if((arr[i]) == (arr.size() - (i+1))) {
            return 1;
        }
    }
    return -1;
}
