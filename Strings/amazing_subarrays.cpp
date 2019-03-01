/*
    https://www.interviewbit.com/problems/amazing-subarrays/
    TC: O(n)
*/

/*
    For each substring starting with a vowel, the max length of that subarray
    is till the length of string starting that index.
    So eg: ABEC
    A, AB, ABE, ABC
*/
int Solution::solve(string str) {
    int subarray_count = 0;
    char c;
    
    for(int i = 0; i < str.size(); i++) {
        c = tolower(str[i]);
        if(c == 'a' || c == 'e' ||c == 'i' ||
           c == 'o' || c == 'u') {
               subarray_count += str.size() - i;
           }
    }
    
    return subarray_count % 10003;
}
