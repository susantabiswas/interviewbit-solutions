/**
 * Vertical order traversal of Binary tree
 * https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
 */

void doVerticalTraversal(TreeNode* root, int curr, map<int, vector<int>>& order) {
    if(!root)
        return;
    
    struct NodeInfo {
        TreeNode* root;
        int idx;
        
        NodeInfo(TreeNode* root, int curr): root(root), idx(curr){}
    };
    
    queue<NodeInfo> q;
    q.emplace(NodeInfo{root, curr});
    
    while(!q.empty()) {
        NodeInfo curr = q.front();
        q.pop();
        
        order[curr.idx].emplace_back(curr.root->val);
        
        if(curr.root->left)
            q.emplace(NodeInfo{curr.root->left, curr.idx - 1});
        
        if(curr.root->right)
            q.emplace(NodeInfo{curr.root->right, curr.idx + 1});
    }
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>> result;
    map<int, vector<int>> order;
    int curr = 0;
    
    doVerticalTraversal(root, curr, order);
    
    for(auto it = order.begin(); it != order.end(); it++) 
        result.emplace_back(move(it->second));
    return result;
}
