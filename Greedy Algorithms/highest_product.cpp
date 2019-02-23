/* https://www.interviewbit.com/problems/highest-product/

    Given an array. return the highest product using three numbers
 */

// TC: O(nlogn)
// largest product can either be from the three largest numbers or
// using the samllest two negative numbers and the largest number
int Solution::maxp3(vector<int> &arr) {
    // sort the numbers
    // we can solve in O(n) without using sort with the
    // help of 5 variables to keep track of largest three numbers and 
    // smallest two negative numbers
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    
    return max(arr[n-1] * arr[n-2] * arr[n-3],
                arr[0] * arr[1] * arr[n-1]);
}
