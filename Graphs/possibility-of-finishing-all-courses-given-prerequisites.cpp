/*
    https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
*/

// SOLUTION 1
bool topologicalSort(int curr, vector<vector<int>>& g,
                    vector<bool>& visited, vector<bool>& rec_stack) {
    // if the same element is in rec stack
    if(rec_stack[curr])
        return false;
        
    rec_stack[curr] = true;
    
    for(int i = 0; i < g[curr].size(); i++) 
        if(!visited[g[curr][i]])
            if(!topologicalSort(g[curr][i], g, visited, rec_stack))
                return false;
    // make current visited
    visited[curr] = true;
    
    // remove curr from rec stack
    rec_stack[curr] = false;
    return true;
}

int Solution::solve(int n_vertices, vector<int> &src, vector<int> &dst) {
    // create a graph
    vector<vector<int>> g(n_vertices);
    // each prerequisite pair is like a directed edge
    for(int i = 0; i < src.size(); i++)
        g[src[i] - 1].emplace_back(dst[i] - 1);

    // now check the graph reachibility
    vector<bool> visited(n_vertices, false), rec_stack(n_vertices, false);
    
    for(int i = 0; i < n_vertices; i++) {
        if(!visited[i])
            // topological sort of graph
            if(!topologicalSort(0, g, visited, rec_stack))
                return false;
    }
    return true;
}

/////////////////////////////////////////////////////
// SOLTUION 2
// Checks if cycle is present using BFS
bool bfsCycle(vector<vector<int>>& g) {
    const int N = g.size();
    // for finding the indegree of vertices
    vector<int> indegree(N, 0);
    // find the indegree of vertices
    for(int i = 0; i < N; i++)
        for(int j = 0; j < g[i].size(); j++)
            ++indegree[g[i][j]];
    
    queue<int> q;
    // tracks no. of visited vertices
    unordered_set<int> visited;
    // start the BFS process with zero indegree vertices
    for(int i = 0; i < N; i++)
        if(indegree[i] == 0)
            q.emplace(i), visited.insert(i);
    
    while(!q.empty()) {
        int curr = q.front();
        //pop it 
        q.pop();
        
        // decrement the indegree of neighbours
        for(int i = 0; i < g[curr].size(); i++) {
            // if already visited
            if(visited.find(g[curr][i]) != visited.end())
                return true;
            --indegree[g[curr][i]];
            if(indegree[g[curr][i]] == 0) 
                q.emplace(g[curr][i]), visited.insert(g[curr][i]);
        }
    }
    // if a cycle is there, vertices part of cycle will be not be visited
    return visited.size() < N;
}

int Solution::solve(int n, vector<int> &B, vector<int> &C) {
    // create a graph with 'n' vertices
    vector<vector<int>> g(n);
    for(int i = 0; i < B.size(); i++)
        g[B[i] - 1].emplace_back(C[i] - 1);
        
    return !bfsCycle(g);
}
