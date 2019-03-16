/*
    Binary search in rotated sorted array
    https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int binSearch(const vector<int>& arr, int l, int h, int k) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] < k)
            l = mid + 1;
        else
            h = mid - 1;
    }    
    
    return -1;
}

int rotatedSearch(const vector<int>& arr, int& k) {
    int l = 0, h = arr.size() - 1;
    
    while(l <= h) {
        int mid = l + (h - l) / 2;
        // if target is found
        if(arr[mid] == k)
            return mid;
        // check if middle is pivot     
        else if(mid - 1 >= 0 && arr[mid - 1] > arr[mid])  {
            // once the pivot is found we check, on which side
            // of pivot can the target lie
            if(arr[arr.size() - 1] >= k) {
                return binSearch(arr, mid + 1, arr.size()-1 , k);
            }
            else if(arr[0] <= k) {
                return binSearch(arr, 0, mid - 1, k);
            }
        }
        else if(arr[h] < arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    
    }
    return -1;
}

int Solution::search(const vector<int> &arr, int k) {
    return rotatedSearch(arr, k);
}
