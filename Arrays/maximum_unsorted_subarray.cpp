/*
  Find the maximum unsorted subarray
  https://www.interviewbit.com/problems/maximum-unsorted-subarray/
*/

vector<int> Solution::subUnsort(vector<int> &arr) {
    int s = INT_MAX;
    int e = INT_MIN;
    int min_el = INT_MAX;
    int max_el = INT_MIN;
    bool unsorted = false;
    
    // find the candidate unsorted region
    for(int i = 1; i < arr.size(); i++) {
        // order is not maintained
        if(arr[i-1] > arr[i]) {
            s = min(s, i-1);
            e = max(e, i);
        }
    }
    
    // find min and max in unsorted range
    if(s != INT_MAX)
        for(int i = s; i <= e; i++) {
            min_el = min(min_el, arr[i]);
            max_el = max(max_el, arr[i]);
        }
        
        
    int start = 0, end = arr.size() - 1;
    if(s != INT_MAX) {
        // check where the min and max can be placed
        // in sorted parts
        for(int i = 0; i < arr.size(); i++) {
            if(i < s && arr[i] <= min_el) 
                start = max(start, i + 1);
            if(i > e && arr[i] >= max_el)
                end = min(end, i - 1);
        }
    }
    // update the start and end indices if it was found that unsorted region
    // extends more than the candidate region
    int final_s = min(start, s);
    int final_e = max(end, e);
    return s == INT_MAX ? vector<int>{-1} : vector<int> {final_s, final_e};
}
