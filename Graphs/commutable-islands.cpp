/*
    https://www.interviewbit.com/problems/commutable-islands/
    TC: O(ElogE)
*/

// finds the cost of MST using Prim's MST
int primMST(vector<vector<pair<int, int> > >& g) {
    int cost = 0;
    // We use a min heap, using weight as the comparison criterion
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                    function<bool(pair<int, int>, pair<int, int>) > >
        min_heap([](const pair<int, int>& a, const pair<int, int>& b)->bool{
            return a.second > b.second;
        });
        
    // add the source vertex
    min_heap.emplace(make_pair(0, 0));
    // to keep track of visited vertices
    vector<bool> visited(g.size(), false);
    //visited[0] = true;
    
    while(!min_heap.empty()) {
        auto curr = min_heap.top();
        min_heap.pop();
        
        // Since a visited can already be inside the heap,
        // process only if unvisited
        if(visited[curr.first] == false) {
            // mark it visited and add to heap
            visited[curr.first] = true;
                      
            // add cost to MST
            cost += curr.second;
            // add the unvisited negibouring vertices with their edge cost
            for(int i = 0; i < g[curr.first].size(); i++) {
                // if the vertex is unvisited
                if(!visited[g[curr.first][i].first]) {
                    min_heap.emplace(g[curr.first][i]);
                }
            }
        }
    }
    
    return cost;
}

int Solution::solve(int V, vector<vector<int> > &edges) {
    // create a graph
    vector<vector<pair<int, int>>> g(V);
    // edge: (start, end, weight), input vertices are 1 indexed 
    for(const auto& edge: edges) {
        g[edge[0]-1].emplace_back(make_pair(edge[1]-1, edge[2]));
        g[edge[1]-1].emplace_back(make_pair(edge[0]-1, edge[2]));
    }
    return primMST(g);
}
