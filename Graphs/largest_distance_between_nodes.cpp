/* Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). The nodes will be numbered 0 through N - 1.

The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N). Exactly one of the i’s will have P[i] equal to -1, it will be root node.

    Example:
    If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 

          0
       /  |  \
      1   2   3
               \
                4  

    One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3. Note that there are other paths with maximal distance. 
     */

//TC: O(n)
int Solution::solve(vector<int> &A) {
    // for keeping tracks of no. of edges under each node
    vector<vector<int>> edges(A.size(), vector<int>(2, 0));
    
    // current edges for the current node
    int curr_edges = 0;
    
    // we start the traversal from the leaf nodes, increment
    // the no. of edges counter for each node. For each node
    // we store two maximum number of edges in its subchilds.
    for(int i = A.size()-1; i > 0; i--){
        // find the max no. of edges out of all its children
        curr_edges = max(edges[i][0], edges[i][1]);    
        //update the edge count for its parent
        if(curr_edges + 1 > min(edges[A[i]][0], edges[A[i]][1])){
            if(edges[A[i]][0] < edges[A[i]][1]){
                edges[A[i]][0] = curr_edges + 1;
            }
            else{
                edges[A[i]][1] = curr_edges + 1;
            }
        }
    }
    
   /* for(auto row: edges){
        for(auto e: row)
            cout << e << " ";
        cout << endl;
    }*/
    int max_length = numeric_limits<long>::min();
    // add the max no. of edges on either sides for each node and return max
    for(int i = 0; i<A.size(); i++){
        edges[i][0] = edges[i][0] + edges[i][1]; 
        if(edges[i][0] > max_length)
            max_length = edges[i][0];
    }
    return max_length;
}
