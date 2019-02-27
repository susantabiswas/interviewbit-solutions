/*
    Find the largest number
    https://www.interviewbit.com/problems/largest-number/

    TC: (nlogn)
*/

struct Comp {
    bool operator()(const string& a, const string& b) const {
        // check which comb is greater
        string num1 = a + b;
        string num2 = b + a;
        
        return num1 > num2;
    }    
};

string Solution::largestNumber(const vector<int> &arr) {
    vector<string> t;
    for(const auto& a: arr)
        t.emplace_back(to_string(a));
    sort(t.begin(), t.end(), Comp());
    
    string number;
    for(const auto& a: t)
        number += a;
        
    // if all the inputs are zero, then answer should be single "0"
    if(number.size() > 1 && number[0] == '0')
        return "0";
    return number;
}
