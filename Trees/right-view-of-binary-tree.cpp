/*
    https://www.interviewbit.com/problems/right-view-of-binary-tree/
    
    Do BFS and traverse from right to left, add the first node to result.
    TC: O(N)
    SC: O(N)
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
vector<int> rightView(TreeNode *root) {
    queue<TreeNode*> q;
    vector<int> result;
    q.emplace(root);
    bool first = true;
    int n_level = q.size();
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        --n_level;
        
        // first node of level
        if(first) {
            result.emplace_back(curr->val);
            first = false;
        }
        
        if(curr->right)
            q.emplace(curr->right);
        if(curr->left)
            q.emplace(curr->left);
        
        if(n_level == 0) {
            first = true;
            n_level = q.size();
        }
    }
    return result;
}

vector<int> Solution::solve(TreeNode* root) {
    return rightView(root);
}
