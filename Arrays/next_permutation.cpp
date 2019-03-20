/*
  Find the next permutation of an array of numbers
  https://www.interviewbit.com/problems/next-permutation/
*/

/*
    To get the next permutation, we just need to have the next greatest number.
    To do that we find the first instance where Ai-1 < Ai, then we swap that i-1 
    with the smallest number greater than i-1, then to ensure the next permutation is just
    the next greater number, we sort the remaining numbers in increasing order so 
    that they form the smallest number.
*/
void placePivot(vector<int>& arr, int start, int pivot) {
    int pivot_val = arr[pivot];
    int smaller =  start - 1, equal = start, greater = arr.size();
    
    // position the pivot 
    while(equal < greater) {
        if(arr[equal] < pivot_val) {
            swap(arr[++smaller], arr[equal]);
            ++equal;
        }
        else if(arr[equal] == pivot_val)
            ++equal;
        else
            swap(arr[--greater], arr[equal]);
    }
    
    // sort the numbers before pivot
    sort(arr.begin() + start, arr.begin() + smaller + 1);
    // sort the numbers after pivot
    sort(arr.begin() + equal, arr.end());
}

void Solution::nextPermutation(vector<int> &arr) {
    bool sorted = true;
    int smallest = arr.back();
    for(int i = arr.size() - 1; i >= 1; i--) {
        
        if(arr[i-1] < arr[i]) {
            // find the smallest number greater than Ai-1
            int k = i;
            int min_greater = i;
            while(k < arr.size()) {
                if(arr[k] > arr[i-1]) {
                    if(arr[k] < arr[min_greater]) 
                        min_greater = k;
                }
                ++k;
            } 
            
            // swap position with that smallest greater number
            swap(arr[i-1], arr[min_greater]);
            // place the smaller number at its pivot position,
            // and sort the numbers before and after pivot
            placePivot(arr, i, min_greater);
            sorted = false;
            break;
        }
    }
    
    // if all the numbers are in non increasing order, return the smallest order
    if(sorted) {
        int i = 0, j = arr.size() - 1;
        while(i < j)
            swap(arr[i++], arr[j--]);
    }
}
