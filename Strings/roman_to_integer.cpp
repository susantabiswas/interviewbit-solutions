/*
    Convert roman numeral to int equivalent
    https://www.interviewbit.com/problems/roman-to-integer/

    TC: O(d), d:no. of digits
*/

int Solution::romanToInt(string str) {
    int value = 0;
    unordered_map<char, int> roman_val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    for(int i = 0; i < str.size(); i++) {
        // if next numeral is greater than current, then 
        // that value + current value makes a value: so current should be subtracted 
        // from next value
        if((i + 1) < str.size() && roman_val[str[i]] < roman_val[str[i+1]]) {
            value -= roman_val[str[i]];
        }
        else {
            value += roman_val[str[i]];
        }
    }
    
    return value;
}
