/*
    https://www.interviewbit.com/problems/magician-and-chocolates/
*/

int Solution::nchoc(int k, vector<int> &arr) {
    priority_queue<int, vector<int>, less<int>> pq;
    const long long MOD = pow(10, 9) + 7;
    
    // fill with all the bag entries
    for(const auto& a: arr)
        pq.emplace(a);
    
    long long max_chocolates = 0;
    // each time choose the bag with max no. of chocolates
    while(k--) {
        int curr_bag = pq.top();
        // remove the bag and push bag with half the amount
        pq.pop();
        pq.emplace(floor(curr_bag/2));
        
        max_chocolates = max_chocolates % MOD + (long long)curr_bag % MOD; 
    }
    
    return max_chocolates % MOD;
}
