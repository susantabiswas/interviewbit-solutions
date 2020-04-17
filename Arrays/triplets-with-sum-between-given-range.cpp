/*
    
    https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
    
    Idea is start with the entire range of selection i.e biggest and smallest
    numbers and adjust the values accordingly to how close we are to the answer.
    
    Sort the numbers.
    Fix 3 ptrs: i(smallest), j(intermediate) and k(biggest).
    
    We move the kth ptr when the sum is bigger and move the jth ptr when sum
    is smaller. ith ptr is only moved when jth ptr can't be moved and the number
    is still smaller, so we start making the smallest number bigger.
    TC: O(NlogN)
*/
int Solution::solve(vector<string> &arr) {
    int i = 0, j = 1, k = arr.size() - 1;
    // sort the numbers
    sort(begin(arr), end(arr));
    
    while(j < k) {
        double a = stof(arr[i]), b = stof(arr[j]), c = stof(arr[k]);
        double sum = a + b + c;
        if(sum > 1 && sum < 2)
            return true;
        // make the biggest number smalller        
        if(sum >= 2) {
            --k;
        }
        // try to make one of the smaller numbers bigger
        else if(sum <= 1) {
            // make jth number bigger only if it can moved 
            // ahead in array, else move the smallest ith number
            if(j+1 < k)
                ++j;
            // if jth number cant be made bigger, try to make the 
            // ith number bigger
            else
                ++i;
            // in order to prevent infinite loop, we need to increment
            // ptrs every time no matter if conditions are true or not
            // so when j is at the same pos as j, increase j
            if(i == j)
                ++j;
        }
    }
    return false;
}
