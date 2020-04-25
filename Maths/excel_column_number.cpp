/*
    https://www.interviewbit.com/problems/excel-column-number/
    
*/
// Solution 1
int Solution::titleToNumber(string str) {
    int col_num = 0;
    
    for(const char& c: str) 
        col_num = col_num*26 + (c - 'A' + 1);
    
    return col_num;
}

// Solution 2
int Solution::titleToNumber(string str) {
    const int BASE = 26;
    
    int value = 0;
    int power = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        value += pow(BASE, power++) * (str[i] - 'A' + 1);
    }
    
    return value;
}
