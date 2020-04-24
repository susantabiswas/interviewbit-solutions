/*
  https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
*/
// TC: O(log(base5)(n))
int Solution::trailingZeroes(int n) {
    int n_five = 0;
    int p = 1, curr_power = 5;
    // find how many 5s are there,
    // for numbers having more 5s like 125,
    // dividing by 5 gives only accounts for 1 five,
    // so we divide by its increasing powers to account for the 
    // remaining.
    while(curr_power <= n) {
        n_five += n / curr_power;
        ++p;
        curr_power = pow(5, p);
    }
    return n_five;
}

/*
    Each zero is contibuted by 10, which is 5X2. So we need to find no. of 5X2 pairs.
    Since there are plenty of even numbers, so we can focus on just no. of 5s. For a 
    given range [1:y], y / 5 gives us the no. of multiples lying in the range. But
    there are numbers which has more than one 5 also like 25, 100, and they have extra 5s.
    To find them we need to divide by 5^2, 5^3 ... till y / 5^p <= 1. So we check we keep increasing
    power of 5 and find no. of multiples for current range each time.
*/
int Solution::trailingZeroes(int num) {
    int num_zeros = 0;
    int p = 1;
    int multiples = 0;
    
    while(true)  {
        // find the no. of multiples of 5^p
        multiples = num / pow(5, p);
        ++p;
        if(multiples == 0)
            break;
        num_zeros += multiples;    
    }
    
    return num_zeros;
}
