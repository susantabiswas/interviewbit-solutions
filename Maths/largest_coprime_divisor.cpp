/*
  https://www.interviewbit.com/problems/largest-coprime-divisor/
*/

int gcd(int A, int B) {
    if(A == B)
        return A;
    if(A == 0 || B == 0)
        return A ? A : B;
    if(A > B)
        return gcd(A - B, B);
    else
        return gcd(A, B - A);
}
int Solution::cpFact(int a, int b) {
    int common = gcd(a, b);
    if(common == 1)
        return a;
    // largest common factor
    int candidate = a / common;
    // starting with largest common factor we keep removing
    // factors of A, till the remaining number has nothing except 1 in common with B
    while(gcd(candidate, b) != 1) {
        candidate = candidate / gcd(candidate, b);
    }
    return candidate;
}
