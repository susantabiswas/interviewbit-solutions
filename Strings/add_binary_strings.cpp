/*
    Add binary numbers
    https://www.interviewbit.com/problems/add-binary-strings/

    TC: O(n)
*/


string Solution::addBinary(string num1, string num2) {
    string result;
    int carry = 0;
    int sum = 0;
    int i = 0, j = 0;
    for(i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--) {
        sum = carry + (num1[i] - '0') + (num2[j] - '0');
        if(sum > 1) {
            carry = 1;
            sum = sum % 2;
        }
        else {
            carry = 0;
        }
        result += to_string(sum);
    }
   
    // if one of the numbers is left
    while(i >= 0) {
        sum = carry + num1[i] - '0';
        if(sum > 1) {
            carry = 1;
            sum = sum % 2;
        }
        else {
            carry = 0;
        }
        result += to_string(sum);
        --i;
    }
    while(j >= 0) {
        sum = carry + num2[j] - '0';
        if(sum > 1) {
            carry = 1;
            sum = sum % 2;
        }
        else {
            carry = 0;
        }
        result += to_string(sum);
        --j;
    }
 
    // if carry is left
    if(carry)
        result += to_string(carry);
        
    // reverse the string
    reverse(result.begin(), result.end());
    return result;
}
