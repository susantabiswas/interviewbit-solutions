/* Find the length of longest increasing decreasing subarray
    https://www.interviewbit.com/problems/length-of-longest-subsequence/
*/

int Solution::longestSubsequenceLength(const vector<int> &arr) {
    int longest_subsequence = 0;
    // for stroing longest increasing lengths
    vector<int> longest_incr(arr.size(), 1);
    // for storing longest decreasing lengths
    vector<int> longest_decr(arr.size(), 1);
    
    // find the longest increasing lengths
    for(int i = 1; i < arr.size(); i++) {
        // find the longest subseq before 'i' st that element is lesser than arr[i]
        for(int k = 0; k < i; k++) {
            if(arr[k] < arr[i]) {
                longest_incr[i] = max(longest_incr[k] + 1,
                                    longest_incr[i]);
            }
        }
    }
    // find the longest decreasing lengths
    for(int j = arr.size() - 2; j >= 0; j--) {
        for(int k = arr.size() - 1; k > j; k--) {
            // find the longest subseq after 'j' st that element is lesser than arr[j]
            if(arr[k] < arr[j]) {
                longest_decr[j] = max(longest_decr[k] + 1,
                                    longest_decr[j]);
            }
        }
    }
    
    int longest_length = 1;
    for(int i = 0; i < arr.size(); i++) {
        longest_length = max(longest_incr[i] + longest_decr[i], 
                            longest_length);
    }
    //cout << longest_length<<endl;
    return longest_length - 1;
}
