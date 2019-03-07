/*  
  Find three elements from 3 arrays such that the diff of max and min is minimized
*/

/*
    We start with the first element of each of the three arrays. Then find the 
    difference, the smallest element index is increased so that it can hope to become 
    comparable to the other two. This is repeated till one of the arrays is ended.
    There is no point in going further for the remaining arrays, because the fact that
    one of the arrays has finished means it had a smaller element, so if we increment
    any other array the gap will only increase.
*/
int Solution::solve(vector<int> &a, vector<int> &b, vector<int> &c) {
    int i = 0, j = 0, k = 0;
    int min_diff = numeric_limits<int> :: max();
    int curr_diff = 0;
    
    while(i < a.size() && j < b.size() && k < c.size()) {
        // find the minimum and maximum values out of three
        int min_val = min({a[i], b[j], c[k]});
        int max_val = max({a[i], b[j], c[k]});
        
        curr_diff = max_val - min_val;
        min_diff = min(min_diff, curr_diff);
        
        // increment the index of smallest element array
        if(min_val == a[i])
            ++i;
        else if(min_val == b[j])
            ++j;
        else
            ++k;
    }
    
    return min_diff;
}
