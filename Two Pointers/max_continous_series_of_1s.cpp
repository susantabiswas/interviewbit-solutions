/*
    Find the max continous series of ones. Zeros can be flipped K times.
    https://www.interviewbit.com/problems/max-continuous-series-of-1s/

    TC: O(n)
*/

/*  
    Range[j:i] maintains the longest sequence of 1s. If the number of zeros in that
    range is more than flips, we try shifting the starting index, otherwise try
    expanding by incrementing i. We track the longest length meanwhile
*/
vector<int> Solution::maxone(vector<int> &arr, int flips) {
    int max_ones = 0;
    int ones_count = 0, zero_count = 0;
    int i = 0, j = 0;
    int max_s = 0, max_e = 0;
    
    if(arr[0] == 0)
        ++zero_count;
    else
        ++ones_count;
        
    while(i < arr.size()) {
        // if the number of zeros is lesser than no. of flips, increase the 
        // range length
        if(zero_count <= flips) {
            ++i;
            if(i >= arr.size())
                break;
            if(arr[i] == 0) {
                ++zero_count;
            }
            else {
                ++ones_count;
            }
            
            if(zero_count <= flips && ones_count + zero_count > max_ones) {
                max_s = j;
                max_e = i;
                max_ones = ones_count + zero_count;
            }
        }
        // since no. of zeros is greater than allowed flips, reduce range length
        else {
            if(arr[j] == 0) {
                --zero_count;
            }
            else {
                --ones_count;
            }
            ++j;
        }
        
    }
    
    vector<int> result;
    for(int i = max_s; i <= max_e; i++)
        result.emplace_back(i);
        
    return result;
}
