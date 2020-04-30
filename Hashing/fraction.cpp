/*
    https://www.interviewbit.com/problems/fraction/
*/

string Solution::fractionToDecimal(int num, int den) {
    if(num == 0)
        return "0";
        
    bool negative = num < 0 ^ den < 0;
    unordered_map<int, int> q_pos;
    string ans, fraction;
    
    long long numerator = abs((long long)num), denominator = abs((long long)den);
    long long quotient = numerator / denominator;
    
    // find the non fractional part
    numerator = numerator % denominator;
    ans = to_string(quotient);
    
    // find the fractional part
    while(numerator) {
        numerator *= 10;
        // check if the same numerator was seen before
        if(q_pos.count(numerator)) {
            // insert the bracket before the quotient of current division
            fraction.insert(q_pos[numerator], "(");
            fraction += ")";
            break;
        }
        if(numerator > denominator) {
            fraction += to_string(numerator / denominator);
            q_pos[numerator] = fraction.length() - 1;
            numerator %= denominator;
        }
        else {
            // num is still smaller
            fraction += "0";
            q_pos[numerator] = fraction.length() - 1;
        }
    }
    
    if(fraction.size())
        ans = ans + "." + fraction;
    // if negative, add the sign
    if(negative)
        ans = "-" + ans;
    return ans;
}
