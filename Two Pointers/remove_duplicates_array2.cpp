/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/ 
*/

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
