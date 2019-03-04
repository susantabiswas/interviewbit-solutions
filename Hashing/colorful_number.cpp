/*
    https://www.interviewbit.com/courses/programming/topics/hashing/
*/

int Solution::colorful(int num) {
    vector<int> digits;
    while(num) {
        digits.emplace_back(num % 10);
        num /= 10;
    }
    
    set<int> s;
    long long prod;
    for(int i = 0; i < digits.size(); i++) {
        prod = 1;
        for(int j = i; j < digits.size(); j++) {
            prod = prod * digits[j]; 
            if(s.find(prod) != s.end()) {
                return 0;
            }
            else {
                s.emplace(prod);
            }
        }
    }
    
    return 1;
}
