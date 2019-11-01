/*
    Search for a target range
    https://www.interviewbit.com/problems/search-for-a-range/
*/
void findRange(const vector<int>& arr, int l, int h, int& k, vector<int>& range,
                bool left) {
    if(l <= h) {
        int mid = l + (h - l) / 2;
        
        // target found, update range
        if(arr[mid] == k) {
            if(range[0] == -1 && range[1] == -1) {
                range[0] = mid;
                range[1] = mid;
            }
            else {
                range[0] = min(mid, range[0]);
                range[1] = max(mid, range[1]);
            }
            // if this is search for lower bound
            if(left)
                findRange(arr, l, mid-1, k, range, left);
            else    // search for upper bound
                findRange(arr, mid+1, h, k, range, left);
        }
        else if(arr[mid] > k)
            findRange(arr, l, mid-1, k, range, left);
        else
            findRange(arr, mid + 1, h, k, range, left);
    }    
}

vector<int> Solution::searchRange(const vector<int> &arr, int k) {
    vector<int> range = {-1, -1};
    // we do two binary searches, each focusing on finding the 
    // extreme end position of target value
    // So we do searches for lower and upper bounds.
    findRange(arr, 0, arr.size() - 1, k, range, true);
    findRange(arr, 0, arr.size() - 1, k, range, false);
    
    return range;
}
