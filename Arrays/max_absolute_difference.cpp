/*
    https://www.interviewbit.com/problems/maximum-absolute-difference/
    TC: O(n)
*/

int Solution::maxArr(vector<int> &arr) {
    int max_val = INT_MIN;
    // the formula can be broken into 4 formulas:
    // just take the mod +- sign and find the 4 cmbs
    // now the first term needs to be maximized and second needs to be minimised
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++) {
        max1 = max(max1, arr[i] + i);
        max2 = max(max2, arr[i] - i);
        max3 = max(max3, -arr[i] + i);
        max4 = max(max4, -arr[i] - i);
        
        min1 = min(min1, arr[i] + i);
        min2 = min(min2, arr[i] - i);
        min3 = min(min3, -arr[i] + i);
        min4 = min(min4, -arr[i] - i);
    }
    
    max_val = max({max1 - min1,
                    max2 - min2,
                    max3 - min3,
                    max4 - min4
    });
    return max_val;
}

// Solution: Other variant
int Solution::maxArr(vector<int> &arr) {
    vector<int> max_term(4, INT_MIN);
    vector<int> min_term(4, INT_MAX);
    int max_diff = INT_MIN;
    
    for(int i = 0; i < arr.size(); i++) {
        // update the max terms
        max_term[0] = max(max_term[0], arr[i] + i);
        max_term[1] = max(max_term[1], arr[i] - i);
        max_term[2] = max(max_term[2], -arr[i] + i);
        max_term[3] = max(max_term[3], -arr[i] - i);
        
        // update the min terms
        min_term[0] = min(min_term[0], arr[i] + i);
        min_term[1] = min(min_term[1], arr[i] - i);
        min_term[2] = min(min_term[2], -arr[i] + i);
        min_term[3] = min(min_term[3], -arr[i] - i);
    }
    
    max_diff = max({
                    max_term[0] - min_term[0],
                    max_term[1] - min_term[1],
                    max_term[2] - min_term[2],
                    max_term[3] - min_term[3]
                });
    return max_diff;
}

