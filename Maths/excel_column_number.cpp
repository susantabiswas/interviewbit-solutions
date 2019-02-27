/*
    https://www.interviewbit.com/problems/excel-column-number/
    
*/

int Solution::titleToNumber(string str) {
    const int BASE = 26;
    
    int value = 0;
    int power = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        value += pow(BASE, power++) * (str[i] - 'A' + 1);
    }
    
    return value;
}
