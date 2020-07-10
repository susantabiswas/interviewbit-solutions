/*
    https://www.interviewbit.com/problems/cycle-in-undirected-graph/
    
    Using Union Find
    TC: O(ElogV)
*/

int getRoot(int &u, vector<int>& root) {
    while(u != root[u])
        u = root[root[u]];
    return u;
}

void unionOp(int &u, int &v, 
        vector<int>& root, vector<int>& size) {
    int root_u = getRoot(u, root);
    int root_v = getRoot(v, root);
    
    if(size[root_u] < size[root_v]) {
        root[root_u] = root_v;
        size[root_v] += size[root_u];
    }
    else {
        root[root_v] = root_u;
        size[root_u] += size[root_v];
    }
}

bool findOp(int &u, int &v, vector<int>& root) {
    return getRoot(u, root) == getRoot(v, root);
}   

int Solution::solve(int n, vector<vector<int> > &edges) {
    vector<int> root(n + 1, -1), size(n + 1, 1);
    for(int i = 1; i <= n; i++)
        root[i] = i;
        
    // Do union of edges and check if a loop exists
    for(auto edge: edges) {
        int u = edge[0], v = edge[1];
        if(!findOp(u, v, root))
            unionOp(u, v, root, size);
        else
            return 1;
    }
    
    return 0;
}
