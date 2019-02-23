/* Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

 */

// Tc: O(m.n)
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(!A)
        return vector<vector<int>>{};
        
    // bfs result
    vector< vector<int> > bfs;
    bfs.emplace_back(vector<int>{});
    queue<TreeNode*> q;
    
    // for current node
    TreeNode* curr = nullptr;
    // start traversal with root
    q.push(A);
    // NULL marks end of a level
    q.push(nullptr);
    
    // current level
    int level = 0;
    
    while(q.size() > 0){
        curr = q.front();
        q.pop();
        
        if(curr != nullptr){
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            bfs[level].emplace_back(curr->val);
        }
        else if(curr == nullptr && q.size() > 0){
            ++level;
            bfs.emplace_back(vector<int>{});
            q.push(nullptr);
        }
    }
    
    return bfs;
}