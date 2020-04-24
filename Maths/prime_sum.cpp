/*
    https://www.interviewbit.com/problems/prime-sum/
*/

// SOLUTION 1
// while generating the primes, check if solution exists
vector<int> Solution::primesum(int n) {
    // since we start the prime calculation with 3, so 2 gets left out, 
    // and the only time when only 2 alone makes sum is 4
    if(n == 4)
        return vector<int>{2,2};
        
    // find all prime numbers till n, we dont save even numbers
    // so mapping for all odd nums: num/2
    vector<int> primes(n/2+1, true);
    // 1 is not prime
    primes[0] = false;
    vector<int> ans(2, -1);
    
    for(int i = 3; i <= n; i += 2) {
        // if only current number is prime, check if it can make sum
        if(primes[i/2]) {
            // mark all its factors as non prime
            for(int j = 2*i; j <= n; j += i) 
                if(j % 2 != 0)
                    primes[j/2] = false;
            
            // now check if there is a number with which it can make the sum
            int other_num = n - i;
            if(other_num <= i && primes[other_num/2] || other_num == 2) {
                // check if answer is lexographically smaller
                if(ans[0] == -1) {
                    ans[0] = other_num, ans[1] = i;    
                }
                else if(ans[0] > other_num) {
                    ans[0] = other_num, ans[1] = i;    
                }
                else if(ans[0] == other_num && i < ans[1]) {
                    ans[0] = other_num, ans[1] = i;    
                }
            }
        }
    }
    return ans;
}


// SOLUTION 2
// generate the primes and do 2-sum search
void generatePrimes(int n, vector<bool>& primes) {
    primes[0] = primes[1] = false;
    // mark all even numbers as non prime
    for(int i = 4; i < n; i += 2)
        primes[i] = false;
    for(int i = 3; i < n; i++) {
        if(primes[i]) {
            // mark all its multiples
            for(int j = 2 * i; j < n; j += i)
                primes[j] = false;
        }
    }
}

vector<int> Solution::primesum(int sum) {
    vector<bool> primes(sum, true);
    generatePrimes(sum, primes);
   
    vector<int> ans = {INT_MAX, INT_MAX};
    // now find the pair
    for(int i = 2, j = primes.size() - 1; i <= j; ) {
        if(primes[i] && primes[j]) {
            if(i + j == sum) {
                if(ans[0] == INT_MAX) {
                    ans[0] = i;
                    ans[1] = j;
                }
                else {
                    if(i == ans[0] && j < ans[1] ) {
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
                ++i, --j;
            }
            else if(i + j < sum) {
                ++i;
            }
            else 
                --j;
        }
        if(!primes[i])
            ++i;
        if(!primes[j])
            --j;
    }
    
    
    return ans;
}
