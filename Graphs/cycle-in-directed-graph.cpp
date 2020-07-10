/*
    https://www.interviewbit.com/problems/cycle-in-directed-graph/
    
    Modified DFS.
    TC: O(V + E)
    SC: O(V)
*/

// Checks if a cycle is present or not
bool cyclePresent(int curr, vector<vector<int>>& g,
        vector<bool>& visited, vector<bool>& rec_stack) {
    // mark it visited and add it to current recursive stack
    visited[curr] = true;
    rec_stack[curr] = true;
    
    // traverse its non visited adjacent neighbors
    for(auto &v: g[curr]) {
        if(rec_stack[v])
            return true;
        if(!visited[v] && cyclePresent(v, g, visited, rec_stack))
            return true;
    }
    // remove the current node from rec stack
    rec_stack[curr] = false;
    return false;
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    // create a graph
    // 1 extra node just so that 1based indexing works fine
    vector<vector<int>> g(n+1);
    for(auto &edge: edges)
        g[edge[0]].emplace_back(edge[1]);
        
    vector<bool> visited(n+1, false), rec_stack(n+1, false);
    // incase there is more than 1 component
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && cyclePresent(i, g, visited, rec_stack))
            return 1;
    }
    return 0;
}
