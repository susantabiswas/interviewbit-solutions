/*
    Find three numbers from array whose sum is closest to target K
    https://www.interviewbit.com/problems/3-sum/
*/

/*
    TC: O(nlogn) + O(n^2) ~ O(n^2)
*/
int Solution::threeSumClosest(vector<int> &arr, int target) {
    // sort the array
    sort(begin(arr), end(arr));
    int closest_sum = 0, min_diff = numeric_limits<int> :: max();
    
    for(int i = 0; i < arr.size(); i++) {
        // Fix arr[i] as constant in a + b + c = t,
        // so it becomes finding j and k such that arr[j] + ar[k] = t - arr[i] is smallest
        // also check for each triplet if it is closest to target
        int j = i + 1, k = arr.size() - 1;
        while(j < k) {
            // sum b + c
            int sum = arr[j] + arr[k];
            // check how close a + b + c  is to target
            if(abs(arr[i] + sum - target) < min_diff) {
                min_diff = abs(arr[i] + sum - target);
                closest_sum = arr[i] + arr[j] + arr[k];
            }
            
            if(sum < target - arr[i])
                ++j;
            else 
                --k;
        }
    }
    return closest_sum;
}


// for a given target, finds two elements whose sum is equal to target
void twoSum(vector<int>& arr, int k, int idx, int& closest_sum, int& closest_diff) {
    int curr_sum = 0;
    for(int i = 0, j = arr.size() - 1; i < j; ) {
        if(i != idx && j != idx) {
            curr_sum = arr[i] + arr[j] + arr[idx];
                
            if(curr_sum > k) 
                --j;
            else if(curr_sum < k)
                ++i;
            else if(curr_sum == k) {
                break;
            }
        }
        else {
            if(i == idx)
                ++i;
            else
                --j;
        }
    }

    int curr_diff = abs(k - curr_sum);
    if(curr_diff < closest_diff) {
        closest_diff = curr_diff;
        closest_sum = curr_sum;
    }
}

int Solution::threeSumClosest(vector<int> &arr, int k) {
    // sort the elements 
    sort(arr.begin(), arr.end());
    int closest_sum = numeric_limits<int> :: min();
    int closest_diff = numeric_limits<int> :: max();
    
    // for each element, check if there are two other elements whose
    // sum with current element is close to target K.
    for(int i = 0; i < arr.size(); i++) {
        twoSum(arr, k, i, closest_sum, closest_diff);
    }
    
    return closest_sum;
}
