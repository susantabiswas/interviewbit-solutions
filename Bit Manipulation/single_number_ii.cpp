/*
    Find the number repeated once in an array where each number is repeated thrice
    https://www.interviewbit.com/problems/single-number-ii/
*/

/*
    Since each number except one is repeate d3 times, so their contribution for
    each digit is also divisble by 3. So if for ith position, required number has:
    1: there will be 3x + 1 ones at ith position
    0: there will be 3x + 1 zeros at ith position
    
    So we use a 32 sized array storing the frequency of ones at each position,
    then we find the positions where the frequency is not divisible by 3, those
    positions have 1 by required number and places where frequency is divisible 
    means required number has 0 there
*/
int Solution::singleNumber(const vector<int> &arr) {
    vector<int> ones(32, 0);
    int mask = 1;
    
    for(int i = 31; i >= 0; i--) {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] & mask)
                ++ones[i];
        }
        mask = mask << 1;
    }
    
    int num = 0;
    
    // create the number
    for(int i = 31; i >= 0; i--) {
        mask = 1;
        // position 1 in mask at ith position
        int shifts = 31 - i;
        while(shifts--)
            mask = mask << 1;
        // if 1 count at ith position is not divisible by 3, 
        // means that required number has 1 here else it has zero
        if(ones[i] % 3 != 0) {
            num = num | mask;
        }
    }
    
    return num;
}
