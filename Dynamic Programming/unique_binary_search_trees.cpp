/*
    Ways to construct unique BST with N nodes with values 1,2...N
    https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
*/

/*
    For given N, each time we can have N nodes as root, and the remaining nodes goes to left and right.
    Now for a given node as root, all the smaller nodes are on left and all the larger ones on right.
    For N nodes, if ith node is root, then all i-1 nodes are on left and all n-i on right. 
    
    So C(n) = C(0)C(n-1) + C(1)C(n-2) ...+ C(n-1)C(0)
    C(n): no. of ways for N nodes
*/
int findBSTWays(int n, vector<int>& dp) {
    // base case:
    // ways to make tree with 0 or 1 node is 1
    if(n <= 1)
        return dp[n] = 1;
        
    if(dp[n] == 0) {
        for(int i = 1; i <= n; i++) {
            dp[n] += findBSTWays(i - 1, dp) * findBSTWays(n - i, dp);
        }
    }
    return dp[n];
}

int Solution::numTrees(int n) {
    vector<int> dp(n+1, 0);
    
    findBSTWays(n, dp);
    return dp[n];
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
