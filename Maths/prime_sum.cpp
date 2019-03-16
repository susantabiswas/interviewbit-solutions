/*
    https://www.interviewbit.com/problems/prime-sum/
*/

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
