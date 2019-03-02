/*
    multiply two string numbers
    https://www.interviewbit.com/problems/multiply-strings/
    TC: O(n*m)
*/

string Solution::multiply(string A, string B) {
    if(A == "0" || B == "0")
        return "0";
        
    // we store the longer number in num1
    string num1 = A.size() > B.size() ? A : B;
    string num2 = A.size() > B.size() ? B : A;
    
    int digit = 0;
    int carry = 0;
    string result;
    int number_size = A.size() + B.size();
    while(number_size-- > 0)
        result += "0";
     
    for(int i = num2.size() - 1; i >= 0; i--) {
        for(int j = num1.size() - 1; j >= 0; j--) {
            // current digit
            digit = carry + (result[i + j + 1] - '0') + (num2[i] - '0') * (num1[j] - '0');
            // set current position digit
            result[i + j + 1] = (digit % 10) + '0';
            // carry 
            carry = digit / 10;
        }
        if(carry) {
            result[i] = carry + '0';
            carry = 0;
        }
        
    }
    
    // remove trailing zeroes
    int i = 0;
    while(result[i] == '0')
        ++i;
    
    return result.substr(i, result.size() - i);
}
