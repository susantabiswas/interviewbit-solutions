/*
    Largest contigous subarray with zero sum. 
    https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
*/
vector<int> Solution::lszero(vector<int> &arr) {
    vector<int> sum(arr.size(), 0);
    unordered_map<int, int> sum_map;
    long long total = 0;
    int longest = INT_MIN;
    int s = -1, e = -1;
    
    // find cummulative sum, diff of two sum values i and j gives range value (i, j]
    for(int i = 0; i < arr.size(); i++) {
        total += arr[i];
        sum[i] = total;
        if(sum[i] == 0) {
            if(i + 1 > longest) {
                longest = i + 1;
                s = 0;
                e = i;
            }
        }
    }
    
    // we get zero sum range when sum[i] equals sum[j],
    // so we find it there exists such an index
    for(int i = 0; i < arr.size(); i++) {
        if(sum_map.find(sum[i]) != sum_map.end()) {
            int curr_len = i - sum_map[sum[i]];
            if(curr_len > longest) {
                longest = curr_len;
                s = sum_map[sum[i]] + 1;
                e = i;
            }
        }
        else
            sum_map[sum[i]] = i;
    }
    
    if(s != -1)
        return vector<int>{arr.begin() + s, arr.begin() + e + 1};
    else
        return vector<int>{};
}
