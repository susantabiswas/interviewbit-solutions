/*
    https://www.interviewbit.com/problems/permutation-swaps/
    
    For any position where the elements are not equal, we do 
    a DFS to check if the required element  can be reached, since the
    elements are unique 1...N, so no two positions will require the same
    element as well and we can safely check for element one by one.
    TC: O(V * (V + E))
    
    Solution 2:
        TC: O(V + ElogV)
        For a non matching position we can do a swap iff the element required
        is reachable from current position or if that is in the same component.
        So using union-find we find all the connected components. We traverse the array
        and for any unequal element check if the current position and the pos 
        where the correct element pos lie in the same component or not.
    
*/
bool dfs(int curr, int& target,
        vector<vector<int>>& g,
        vector<int>& arr, vector<bool>& visited) {
    
    
    if(visited[curr])
        return false;
    if(arr[curr] == target)
        return true;
    
    visited[curr] = true;
    for(auto v: g[curr])
        if(dfs(v, target, g, arr, visited))
            return true;
    return false;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &edges) {
    int n = A.size();
    // create a graph
    vector<vector<int>> g(n + 1);
    for(auto &edge: edges) {
        int u = edge[0] - 1, v = edge[1] - 1;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    // Now for any position that doesnt match we
    // check if using the edges we can get to that element
    // that should be there
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i]) {
            vector<bool> visited(n, false);
            if(!dfs(i, B[i], g, A, visited))
                return 0;
        }
    }
    return 1;
}
