/*
    https://www.interviewbit.com/problems/remove-half-nodes/
    
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
TreeNode* Solution::solve(TreeNode* root) {
    // if current node is leaf or null
    if(!root || (!root->left && !root->right))
        return root;
    TreeNode* left = solve(root->left);
    TreeNode *right = solve(root->right);
    
    // if the current node won't be deleted
    // connect the child nodes with it
    if(root->left && root->right) {
        root->left = left;
        root->right = right;
        return root;
    }
    // if the current node has only one child
    else {
        delete root;
        return left ? left : right;
    }
}
