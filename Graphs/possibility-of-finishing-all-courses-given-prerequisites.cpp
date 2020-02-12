/*
    https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
*/

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
