/*
    Max rain water that can be trapped
    https://www.interviewbit.com/problems/rain-water-trapped/
    TC: O(n)
    SC: O(n)
*/

int Solution::trap(const vector<int> &arr) {
    
    int water_trapped = 0;
    vector<int> left_bound(arr.size());
    // first we do a forward pass: For each position we should know the 
    // tallest height till there, including itself, as that will be
    // left boundary for water storage
    for(int i = 0; i < arr.size(); i++) {
        if(i == 0) {
            left_bound[i] = arr[i];
        }
        else {
            // check if there is any bar taller than current bar
            left_bound[i] = max(arr[i], left_bound[i-1]);
        }
    }
    
    int water_storage_height;
    int max_right_height = arr.back();
    // backward pass: we find the tallest bar height in right side inclusive of
    // current bar, this is the right bound for water storage.
    
    // Now water that can be trapped for bar 'i' will be min(h(left), h(right)) - h(i) 
    // h:height, i : current bar
    for(int j = arr.size() - 1; j >= 0; j--) {
        // max height of any bar in right inclusive of current
        max_right_height = max(max_right_height, arr[j]);
        // amt of water that can be stored will be till the lower of left or right bound
        water_storage_height = min(left_bound[j], max_right_height);
        // water that can be trapped depends on the depth formed by the bounds
        // depth will be determined by current bar height
        water_trapped += water_storage_height - arr[j];
    }
    
    return water_trapped;
}
