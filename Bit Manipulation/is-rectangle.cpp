/*
    https://www.interviewbit.com/problems/is-rectangle/
    
    Since we are given side length and nothing about the
    orientation, we can just check if there are 2 pairs
    of sides of equal lengths.
    So we check for 2 pairs of same length.
    
    TC: O(1)
*/
bool isRectangle(int &a, int &b, int &c, int &d) {
    /*
        __a__
        |   |
        d   b
        |   |
        __c__
    */
    return (a == c && d == b) ||
            (a == b && c == d);
}

int Solution::solve(int a, int b, int c, int d) {
    return isRectangle(a, b, c, d);
}
