/*
    https://www.interviewbit.com/courses/programming/topics/hashing/
*/
// Solution 1
// TC: O(d^2), d: no. of digits in number
// or TC: O(log10(n) ^ 2)
int Solution::colorful(int n) {
    unordered_set<int> product;
    string num = to_string(n);
    
    for(int i = 0; i < num.size(); i++) {
        long long prod = 1;
        for(int j = i; j < num.size(); j++) {
            // find the product of current subsequence
            prod = prod * (num[j] - '0');
            // check if the same product existed before or not
            if(product.find(prod) != product.end())
                return 0;
            // insert the product in hash table
            product.emplace(prod);
        }
    }
    return 1;
}


//Solution 2
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
