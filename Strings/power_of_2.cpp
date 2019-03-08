/*
    Check if given number is a power of 2
    https://www.interviewbit.com/problems/power-of-2/
*/

// divides the number by 2
string divideByTwo(string num) {
    string result;
    if(num.size() == 1) {
        int digit = num[0] - '0';
        return to_string(digit / 2);
    }
    
    int carry = 0;
    int i = 0;
    // check the first two digits
    int first_two = stoi(num.substr(0, 2));
    i += 2;
    result += to_string(first_two / 2);
    carry = first_two % 2;
    
    while(i < num.size()) {
        int curr = carry * 10 + num[i] - '0';
        
        if(curr == 0)
            result += '0';
        else {
            result += to_string(curr / 2);
            carry = curr % 2;
        }
        
        ++i;
    }
    
    return result;
}

int Solution::power(string num) {
    if(num == "1")
        return 0;
    string curr_num = num;
    string new_num;
    
    while(true) {
        int n = curr_num.size();
        int digit = curr_num[n - 1] - '0';
        
        // check if current number is evene or odd
        // if even, divide by half
        if(digit % 2 == 0) {
            new_num = divideByTwo(curr_num);        
        }
        // if odd check if it is 1, else return 0
        else {
            if(digit == 1 && curr_num.size() == 1)
                return 1;
            else
                return 0;
        }
        
        curr_num = new_num;
    }
    
    return 1;
}
