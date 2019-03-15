/*
    Check if a string is a valid number
    https://www.interviewbit.com/problems/valid-number/
*/

int Solution::isNumber(const string str) {
    
    // if no digits
    if(str.empty())
        return 0;
    int i = 0;    
    
    // remove starting spaces
    while(i < str.size() && str[i] == ' ')
        ++i;
    if(i == str.size())
        return 0;
        
    if(str[0] == '+' || str[0] == '-') {
        if(str.size() == 1)
            return 0;
        // skip the sign and check for rest    
        ++i;
    }
    
    bool exponent = false;
    
    for(; i < str.size(); ) {
        char c = str[i];
        // valid characters
        if(c == '.' || c == 'e' || (c - '0' >= 0 && c - '0' <= 9) || c == '-') {
            // if it is a decimal, then only a digit/sign is allowed 
            // to preceede it 
            if(c == '.') {
                // decimal can't appear after e
                if(exponent)
                    return 0;
                    
                if((i == 0 || (str[i-1] == '-' || str[i-1] == '+' ||
                            isdigit(str[i-1]) )) && (i+1) < str.size() && 
                                isdigit(str[i+1]))
                    ++i;
                else {//cout<<"1\n";
                    return 0;
                }
            }
            else if(c == 'e') {
                exponent = true;
                // it should be preceeded by a digit and can be followed by a sign
                // or digit
                if(i != 0 && ((i + 1 < str.size()) && (str[i+1] == '-' || 
                                str[i+1] == '+' || isdigit(str[i+1]))))
                    ++i;
                else {
                    return 0;
                }
            }
            else if(c - '0' >= 0 && c - '0' <= 9) {
                ++i;
            }
            else if(c == '-') {
                if(str[i-1] == 'e' && (i+1 < str.size() && isdigit(str[i+1])))
                    ++i;
                else
                    return 0;
            }
        }
        // acc. to question a space is valid !
        else if(c == ' ')
            ++i;
        else {
            return 0;
        }
    }
    return 1;
}
