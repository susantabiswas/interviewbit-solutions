/*
  https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
*/

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
