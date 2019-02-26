/*
    https://www.interviewbit.com/problems/fizzbuzz/ 
    TC: O(n)
*/

vector<string> Solution::fizzBuzz(int n) {
    vector<string> result(n);
    
    for(int i = 1; i <= n; i++) {
        result[i - 1] = !(i % 3) && !(i % 5) ? "FizzBuzz" :
                    !(i % 3) ? "Fizz" :
                    !(i % 5) ? "Buzz" :
                    to_string(i);
    }
    return result;
}
