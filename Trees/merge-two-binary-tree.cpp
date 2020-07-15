/*
    https://www.interviewbit.com/problems/merge-two-binary-tree/
    
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
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return nullptr;
    if(!root1 || !root2)
        return root1 ? root1 : root2;
        
    int val = root1->val + root2->val;
    TreeNode *node = new TreeNode(val);
    node->left = solve(root1->left, root2->left);
    node->right = solve(root1->right, root2->right);
    return node;
}
