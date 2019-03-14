/*
    Find inversions in an array
    https://www.interviewbit.com/problems/inversions/
*/

// merges two arrays and meanwhile counts the number of inversions also
int merge(vector<int>& arr, int start, int end, int middle) {
    if(start >= end)
        return 0;
    
    // first array
    const int N = middle - start + 1;
    // second array
    const int M = end - middle;
    int inversions = 0;
    
    vector<int> temp(N + M);

    int i, j, k;
    for(i = 0, j = 0, k = 0; i < (N + M) && j < N && k < M; i++) {
        // if inversion is there
        if(arr[j + start] > arr[k + middle + 1]) {
            // if element from right hand side array is smaller means 
            // that is an inversion, so all the elements from current
            // in left array will be inversions for that right element
            inversions += N - j;
            temp[i] = arr[k + middle + 1];
            ++k;
        }     
        else {
            temp[i] = arr[j + start];
            ++j;
        }
    }
   
    while(j < N) {
        temp[i++] = arr[start + j];
        ++j;
    }
    while(k < M) {
        temp[i++] = arr[middle + 1 + k];
        ++k;
    }
    
    for(int i = 0; i < temp.size(); i++)
        arr[i + start] = temp[i];

    return inversions;
}

int countInversionsArray(vector<int>& arr, int i, int j) {
    if(i == j)
        return 0;
    
    if(i < j) {
        int mid = i + (j - i) / 2;
        int left_inv = countInversionsArray(arr, i, mid);
        int right_inv = countInversionsArray(arr, mid + 1, j);
    
        return left_inv + right_inv + merge(arr, i, j, mid);
    }
}

int Solution::countInversions(vector<int> &arr) {
    int inversions = countInversionsArray(arr, 0, arr.size() - 1);

    return inversions;
}
