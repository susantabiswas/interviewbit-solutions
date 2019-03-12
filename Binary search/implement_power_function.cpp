/*
  Implement power function
  https://www.interviewbit.com/problems/implement-power-function/
*/

long long findPower(int x, int n, int d) {
    if(n == 0)
        return 1 % d;
    if(n == 1)
        return (x < 0 ? (x + d) : x ) % d;
    if(n == -1) {
        return ( x < 0 ? (1 / x + d) : 1 / x )% d;
    }    
    long long p = findPower(x, n / 2, d);
    
    // if the number is negative to make the mod +ve, we add the mod 
    // number
    if(p < 0)
        p += d;
        
    if(n % 2 == 0) 
        return p%d * p%d;
    else
        return p%d * p%d * x%d;
}

int Solution::pow(int x, int n, int d) {
    return (int)findPower(x, n, d) % d;
}
