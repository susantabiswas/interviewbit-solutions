/*
    Longest common prefix
    https://www.interviewbit.com/problems/longest-common-prefix/

    TC: O(m * n), m: length of prefix, n: no. of strings in array
*/

/*
    Since the prefix should be part of every string, so we start with chars of
    string 1, for each char we check at that position in rest of the strings
    their char match or not, whenever any char doesn't match or if the length
    of any string is lesser than current index we quit
*/
string Solution::longestCommonPrefix(vector<string> &arr) {
    string prefix = "";
    bool char_present = true;
    
    if(arr.size() < 1)
        return prefix;
        
    int i = 0;
    while(1) {
        // current char of 1st string which will be checked in other strings
        char current = arr[0][i];
        char_present = true;
        
        // check if this there in all the strings or not
        for(const string s: arr) {
            // if the string length is shorter, then the prefix 
            // can't exist for any longer length
            if(s.size() <= i) {
                char_present = false;
                break;
            }
            
            // if current prefix char isn't there in string then the prefix
            // can't go longer
            if(s[i] != current) {
                char_present = false;
                break;
            }
        }
        
        ++i;
        // since current char is there in every string, append it to prefix string
        if(char_present)
            prefix += current;
        else
            break;
    }
    
    return prefix;
}
