/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/ 
*/
/*
    abstractive text summarization
    
    TC: O(N), SC; O(1)
*/
int Solution::removeDuplicates(vector<int> &arr) {
    if(arr.size() <= 1)
        return 1;
        
    // pos to where the last element was written
    int write_idx = 0;
    int i = 0;
    // handle the first element
    if(arr[0] == arr[1])
        i += 2, write_idx += 1;
    else
        i = 1;
        
    while(i < arr.size()) {
        if(arr[write_idx] != arr[i]) {
            arr[++write_idx] = arr[i];
            // if the next element is also same, write that also
            if(i+1 < arr.size() && arr[i+1] == arr[i]) {
                arr[++write_idx] = arr[i+1];
                ++i;
            }
        }
        ++i;
            
    }
    return write_idx + 1;
}


int Solution::removeDuplicates(vector<int> &arr) {
    int i = 1; 
    int curr_count = 1;
    int write_idx = 1;
    /*
        Everytime check if previous element is same or not, 
        if same then it this is the second instance of that element,
        write current element at write index.
        if diff element: write current element at write index
        
        move to next
    */
    while(i < arr.size()) {
        if(arr[i-1] == arr[i]) {
            if(curr_count < 2) {
                arr[write_idx++] = arr[i];
            }
            ++curr_count;
            ++i;
        }
        else {
            curr_count = 1;
            arr[write_idx++] = arr[i];
            ++i;
        }
    }
    return write_idx;
}
