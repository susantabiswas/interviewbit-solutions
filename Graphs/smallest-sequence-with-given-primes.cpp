/*
    https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
    
    TC: O(k * 4) ~ O(k)
    
    We treat each number as a vertex. Each neighbouring vertex is formed by multiplication
    of current by any one of the primes.
*/
vector<int> Solution::solve(int a, int b, int c, int k) {
    // we use a priority queue for storing the numbers 
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // for storing the result
    vector<int> result;
    // for keeping track of unique numbers
    unordered_set<int> visited;
    // vector of given primes
    vector<int> primes = {a, b, c};
    
    // initial prime numbers will be the starting vertices
    for(const int& prime : primes) {
        if(visited.find(prime) == visited.end()) {
            min_heap.emplace(prime);
            // mark as visited
            visited.emplace(prime);
        }
    }
    
    while(!min_heap.empty() && k--) {
        int curr = min_heap.top();
        min_heap.pop();
        // add to result
        result.emplace_back(curr);
        
        // now add its adjacent nodes, since its neighbours can 
        // only be formed using a, b and c, multiplication with each one is the
        // neighbouring vertex. Make sure they are unvisited
        for(const int& prime: primes) {
            if(visited.find(curr * prime) == visited.end()) {
                min_heap.emplace(curr * prime);
                // mark as visited
                visited.emplace(curr * prime);
            }
        }
    }
    return result;
}
