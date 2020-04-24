/*
    Check if an integer can be represented in A^p , A > 0 and p > 1
    https://www.interviewbit.com/problems/power-of-two-integers/
*/
/*
    https://www.interviewbit.com/problems/power-of-two-integers/
    
    TC: O(sqrt(n))
    
    Article for float comparison
    https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
*/
int Solution::isPower(int n) {
    if(n == 1)
        return 1;
    int limit = sqrt(n);
    
    for(int i = 2; i <= limit; i++) {
        // any A^p will be able to divide it
        if(n % i == 0) {
            // check if A^p property holds
            double p = log(n)/log(i);
            // check if p is an integer
            double diff = fabs(p - (double)(floor(p)); 
            // floating pt comparison with relative error margin
            // epsilon is the smallest representable number, but it can
            // be larger for error comparison when numbers are same, so
            // we use relative epsilon
            if(diff < numeric_limits<double>::epsilon() * p)
                return 1;
        }
    }
    return 0;
}

int Solution::isPower(int num) {
    // can't use log on 1, result is 0
    if(num == 1)
        return 1;
        
    int num_limit = floor(sqrt(num));
    for(int i = 2; i <= num_limit; i++) {
        // find the value of power p
        int p = log10(num) / log10(i);
        
        // check if it i ^ p == num
        if(pow(i, p) == num)    
            return 1;
    }
    return 0;
}
