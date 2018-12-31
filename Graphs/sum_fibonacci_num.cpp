/*
https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/ 

Find min number of fibonacci numbers required for making the input number by addition.
Repetition is allowed
 */

/* Greedy solution 
    TC: O(n)
*/
vector<int> generateFibonacci(int n){
    if(n <= 0)
        return vector<int>{};
    if(n == 1)
        return vector<int>{1};
        
    vector<int> fib{1, 1};
    int first = 1;
    int second = 1;
    
    int curr = -1;
    
    while(second < n){
        fib.emplace_back(first + second);
        // sum of last two numbers
        second = second + first;
        // last number
        first = second - first;
    }
    return fib;
}

int Solution::fibsum(int A) {
    vector<int> fib = generateFibonacci(A);
    
    int nums = 0;
    int i = fib.size() - 1;
    
    // follow a greedy approach
    while(A){
        if(fib[i] <= A){
            nums = nums + A/fib[i];
            A = A % fib[i];
        }    
        --i;
    }
    return nums;
}
