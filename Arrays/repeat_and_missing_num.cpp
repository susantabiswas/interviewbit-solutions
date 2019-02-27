/*
    https://www.interviewbit.com/problems/repeat-and-missing-number-array/
    TC: O(n)
*/

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    // find the XOR of array range
    long long range_xor = 0;
    for(const auto& a: arr)
        range_xor ^= a;
        
    // find the xor of total range
    int total_xor = 0;
    for(int i = 1; i <= arr.size(); i++) {
        total_xor ^= i;
    }
    
    // A XOR B
    long long a_xor_b = total_xor ^ range_xor;
    
    // now the last set bit in a^b, means either of them has 1 there
    // but we don't know which one. So do XOR of all the numbers with 
    // set bit at that position from both the array and [1:N] range
    // The result is either A or B
    long long last_set_bit = a_xor_b & ~(a_xor_b - 1);
    
    int total_xor_set_bit = 0;
    for(int i = 1; i <= arr.size(); i++) {
        if(i & last_set_bit)
            total_xor_set_bit ^= i;
    }
    int range_xor_set_bit = 0;
    for(const auto& a: arr)
        if(a & last_set_bit)
            range_xor_set_bit ^= a;
        
    int a_or_b = total_xor_set_bit ^ range_xor_set_bit;
    
    vector<int> result;
    // now we just need to know whether it is a or b
    for(const auto& a: arr)
        if(a == a_or_b) {// this is A
            result.emplace_back(a);
            result.emplace_back(a_xor_b ^ a);
            return result;
        }
    
    // if that value was not present, means that was B
    result.emplace_back(a_xor_b ^ a_or_b);
    result.emplace_back(a_or_b);
    
    return result;
}
