/*
    Find number of valid triangles that can be formed
    https://www.interviewbit.com/problems/counting-triangles/
*/

/*
    For a triangle : A <= B <= C
    and sum of two sides > third sides
    a + b > c
    
    Sort the array.
    So we start with tthe largest side and then search for the A and B such that 
    A is the smallest possible and B largest possible. Then all the sides before B
    till A form a valid triangle with B and C, add that number. Then we try reducing B
    and check if the sides are still valid, else increase A by going forward.
    
    TC: O(n^2)
*/
int Solution::nTriang(vector<int> &arr) {
    if(arr.size() < 3)
        return 0;
    
    int mod = pow(10, 9) + 7;
    int num = 0;
    int i = 0, j = 1, k = 2;
    
    sort(arr.begin(), arr.end());
    // k represents the largest side C
    while(k < arr.size()) {
        // search for two sides A and B
        i = 0, j = k - 1;
        while(i < j) {
            int sum = arr[i] + arr[j];
            // valid triangle is formed, so A can have
            // (j - i) no. of sides with B and C fixed
            if(sum > arr[k]) {
                num += (j - i) % mod;
                num = num % mod;
                // try going for a smaller B
                --j;
            }
            else
                // when triangle is not valid, try increasing A
                ++i;
        }
        // Reduce length for C
        ++k;
    }
    return num % mod;
}
