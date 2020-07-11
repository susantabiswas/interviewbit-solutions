/*
    https://www.interviewbit.com/problems/snake-ladder-problem/
    
    Idea is to use BFS to find the min distance to reach the final position.
    We create a graph with nodes(1-100) and the edges can be dervied from snakes
    and ladders.
    
    TC: O(100)
*/

int Solution::snakeLadder(vector<vector<int> > &ladders,
                vector<vector<int> > &snakes) {
    
    // create a directed graph with nodes from 1 to 100
    vector<vector<int>> g(101);
    for(auto edge: ladders)
        g[edge[0]].emplace_back(edge[1]);
    for(auto edge: snakes)
        g[edge[0]].emplace_back(edge[1]);
        
    queue<int> q;
    int level = 0, n_level = 0;
    // to keep track of visited positions
    vector<bool> visited(101, false);
    // mark the starting pos
    visited[1] = true;
    q.emplace(1);
    n_level = q.size();
    
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        --n_level;
        
        // if the destination is reached
        if(pos == 100)
            return level;
        // add the positions reachable from current position
        // using the dice throw
        for(int i = 1; i <= 6; i++) {
            int new_pos = pos + i;
            if(new_pos >= 1 && new_pos <= 100) {
                // check if there is a ladder or snake 
                // if yes then follow the path
                if(g[new_pos].size()) {
                    new_pos = g[new_pos][0];
                }
                // if the current pos is not visited, add and mark it visited
                if(!visited[new_pos]) {
                    q.emplace(new_pos);
                    visited[new_pos] = true;    
                }
             }
        }
        if(n_level == 0) {
            n_level = q.size();
            ++level;
        }
    }
    return -1;
}
