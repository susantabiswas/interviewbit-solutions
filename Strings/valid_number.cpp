/*
    Check if a string is a valid number
    https://www.interviewbit.com/problems/valid-number/
*/

// Solution 1
int Solution::isNumber(const string str) {
    // create new string without any space
    // remove extra white space from beginning and end
    // stupid platform bug
    string s;
    for(int i = 0; i < str.size(); i++)
        if(str[i] != ' ')
            s += str[i];
            
    if(s.empty())
        return false;
    
    int i = 0;
       
    // check for sign, it is allowed only at 0th pos
    // if there is only - in string, false
    if(s[0] == '-' || s[0] == '+') {
        if(s.size() == 1)
            return false;
        ++i;
    }
    
    // skip all preceeding 0s/numbers
    while(i < s.size()) {
        // if not numeric, e or .
        if(!isdigit(s[i]) && s[i] != '.' && s[i] != 'e')
            return false;
        // fractional part will start after this
        if(s[i] == '.' || s[i] == 'e') {
            ++i;
            break;
        }
        ++i;
    }
    // if the last char was '.', check the fractional part
    if(s[i-1] == '.') {
        // check if there is a digit next
        if(i == s.size())
            return false;
        
        // next char after . should be a digit
        if(i < s.size() && !isdigit(s[i]))
            return false;
    
        ++i;
        // fractional part exists, check the fractional part
        // go till the string finishes or e is reached
        while(i < s.size()) {
            if(i < s.size() && !isdigit(s[i]) && s[i] != 'e')
                return false;
            if(s[i] == 'e') {
                ++i;
                break;
            }
            ++i;
        }
    }
    // if exponent part has reached
    if(s[i-1] == 'e') {
        // check the exponent part
        // after e, only +,-, digit is allowed excluding 0
        if(i == s.size() || s[i] == '0')
            return false;
        // first char after e is invalid
        if(s[i] != '+' && s[i] != '-' && !isdigit(s[i]))
            return false;
        ++i;
        // only integers are allowed after this point
        while(i < s.size()) {
            if(i < s.size() && !isdigit(s[i]))
                return false;
            ++i;
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////
// Solution 2
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
