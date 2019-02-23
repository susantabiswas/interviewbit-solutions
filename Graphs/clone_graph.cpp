/* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. */
//TC: O(V + E)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
void cloneUsingDFS(UndirectedGraphNode* orig, UndirectedGraphNode* curr_clone,
                    unordered_map<int, UndirectedGraphNode*>& visited){
    // mark the current node visited
    visited[orig->label] = curr_clone;
        
    // traverse the adjacent nodes
    for(UndirectedGraphNode* v: orig->neighbors){
        if(visited.find(v->label) == visited.end()){
            // make a copy, mark visited and recurse
            UndirectedGraphNode* v_copy = new UndirectedGraphNode(v->label);
            // recurse 
            cloneUsingDFS(v, v_copy, visited);
        }
        // make a copy of the edge
        curr_clone->neighbors.emplace_back(visited[v->label]);
    }
}


UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(!node)
        return nullptr;
        
    // cloned graph source
    UndirectedGraphNode* clone = nullptr;
    // for keeping track of visited nodes
    unordered_map<int, UndirectedGraphNode*> visited;
    
    // we will start with the root node
    // make a clone of it and make it visited
    clone = new UndirectedGraphNode(node->label);
    
    // here DFS will be used for cloning
    cloneUsingDFS(node, clone, visited);
    return clone;
}
