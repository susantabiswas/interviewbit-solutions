/*
    https://www.interviewbit.com/problems/cousins-in-binary-tree/
    
    Use BFS to look for the node whose child is B, then exit he traversal after
    finishing that level. The queue will have all the nodes of the level in which
    B exists, save all the nodes except for B and its sibling.
    TC: O(N)
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> result;
    bool node_found = false;
    TreeNode *sibling = nullptr;
    queue<TreeNode*> q;
    q.emplace(root);
    int n_level = q.size();
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        --n_level;
        // If the left child is B, save the sibling
        if(curr->left && curr->left->val == B) {
                node_found = true;
                sibling = curr->right ? curr->right : nullptr;
        }
        // If the right child is B, save the sibling 
        if(curr->right && curr->right->val == B) {
            node_found = true;
            sibling = curr->left ? curr->left : nullptr;
        }
        
        if(curr->left)
            q.emplace(curr->left);
        if(curr->right)
            q.emplace(curr->right);
            
        if(n_level == 0) {
            n_level = q.size();
            if(node_found)
                break;
        }
    }
    // Add all the nodes of the level in which B exists
    // except for its sibling and itself
    while(!q.empty()) {
        auto curr = q.front();
        if(curr != sibling && curr->val != B)
            result.emplace_back(curr->val);
        q.pop();
    }
    return result;
}
