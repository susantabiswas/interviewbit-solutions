/*
    Wave array
    https://www.interviewbit.com/problems/wave-array/
*/

/*  
    Sort the array first, IMP!!
    We are concerned with only two elements at a time.
    a1 >= a2 should be noticed for each pair. We they follow 
    the rule, go to next pair else swap the two values and go to next.
    This logic works only when the array is sorted
*/
vector<int> Solution::wave(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i += 2) {
        if(arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    return arr;
}
