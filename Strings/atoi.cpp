/*
  Implement atoi
  https://www.interviewbit.com/problems/atoi/
*/

int Solution::atoi(const string str) {
    int number;
    int i = 0;
    // ignore starting spaces
    while(i < str.size() && str[i] == ' ')
        ++i;
    
    if(i == str.size())
        return 0;
        
    // check if number is negative
    bool negative = false;
    
    if(str[i] == '-') {
        negative = true;
        ++i;
    }
    else if(str[i] == '+') {
        negative = false;
        ++i;
    }
    
    // start parsing the word
    // if at any point it is found that the word doesn't
    // have a valid digit or the number exceeds what an int can store, we return 0
    while(i < str.size() && isdigit(str[i])) {
        int digit = str[i] - '0';
        // check for overflow / underflow
        if(number > INT_MAX / 10)
            return negative ? INT_MIN : INT_MAX;
            
        number = number * 10 ;
        
        // check for overflow / underflow
        if(number > INT_MAX - digit)
            return negative ? INT_MIN : INT_MAX;
        number += digit;
        
        ++i;
    }
    
    return negative ? -1 * number : number;
}
