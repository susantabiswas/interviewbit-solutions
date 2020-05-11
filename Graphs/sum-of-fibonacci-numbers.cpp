/*
    https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
*/

// DP solution: Partially accepted
// TC: O(mn), m: no. of fibonacci numbers, n: input number
int dpFibsum(vector<long long>& fibonacci, int N) {
    // get the min fibonacci numbers required using 
    // DP similiar to coin change problem
    vector<long long> dp(N + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= N; i++) 
        for(const int fib: fibonacci) {
            int with_current = i - fib;
            if(with_current >= 0)
                dp[i] = min(dp[i], 1 + dp[with_current]);
        }
    
    return dp[N];
}

// Greedy solution
// TC: O(m), m: no. of fibonacci numbers
int greedyFibsum(vector<long long>& fibonacci, int N) {
    // greedy approach
    int min_fib = 0;
    int fib_idx = fibonacci.size() - 1;
    while(N) {
        if(fibonacci[fib_idx] <= N) {
            min_fib += N / fibonacci[fib_idx];
            N = N % fibonacci[fib_idx];
        }
        --fib_idx;
    }
    return min_fib;    
}

// Using BFs, partially accepted
int bfs(int n, vector<int>& fib) {
    queue<int> q;
    unordered_set<int> visited;
    int level = 1;
    // add the starting nodes, starting nodes are all the fibonacci numbers
    for(int i = 1; i < fib.size(); i++) {
        q.emplace(fib[i]);
        // mark them visited
        visited.emplace(fib[i]);
    }
    int n_level = q.size();
        
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        --n_level;
        
        // if the sum has reached the target
        if(curr == n)
            break;
        
        for(int i = 1; i < fib.size(); i++)
            if(curr + fib[i] <= n && !visited.count(curr + fib[i])) {
                visited.emplace(curr + fib[i]);
                q.emplace(curr + fib[i]);
            }
        
        // level ended
        if(n_level == 0) {
            ++level;
            n_level = q.size();
        }
    }
    
    return level;
}

int Solution::fibsum(int N) {
    if(N <= 1)
        return N;
    // for storing the fibonaaci numbers
    vector<long long> fibonacci(2, 0);
    fibonacci[0] = fibonacci[1] = 1;
    // generate the fibonacci numbers till it is smaller than N
    for(int i = 2; fibonacci[i-1] < N; i++)
        fibonacci.emplace_back(fibonacci[i-1] + fibonacci[i-2]);
     
    // return bfs(N, fibonacci);
    // return dpFibsum(fibonacci, N);
    return greedyFibsum(fibonacci, N);
}
