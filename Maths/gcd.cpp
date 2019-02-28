/*  GCD of two numbers
    https://www.interviewbit.com/problems/greatest-common-divisor/
*/
int Solution::gcd(int A, int B) {
    if(A == B)
        return A;
    if(A == 0 || B == 0)
        return A ? A : B;
    if(A > B)
        return gcd(A - B, B);
    else
        return gcd(A, B - A);
}
