/*
  https://www.interviewbit.com/problems/different-bits-sum-pairwise/
*/


/*
    For each position we find how many numbers have 1 and 0 there.
    Total sum that can be made is 2*ones*zeros. As each one can make a sum with
    other from other side, and this can be done for the other side also.
*/
int Solution::cntBits(vector<int> &arr) {
    long long sum = 0;
    int ones = 0, zeros = 0;
    int mask = 1;
    const long long mod = pow(10, 9) + 7;
    
    // for each bit position find the numbers which have 1 and 0
    for(int i = 0; i < 32; i++) {
        ones = 0, zeros = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] & mask)
                ++ones;
            else
                ++zeros;
        }
        sum = sum % mod + (2 * (ones % mod) * (zeros % mod)) % mod; 
        mask = mask << 1;
    }
    return sum % mod;
}
