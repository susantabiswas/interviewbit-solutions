/* Invert binary tree
    https://www.interviewbit.com/problems/invert-the-binary-tree/

    TC: O(n)
 */


TreeNode* Solution::invertTree(TreeNode* root) {
    if(!root)
        return nullptr;
        
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    
    root->left = r;
    root->right = l;
    return root;
}
