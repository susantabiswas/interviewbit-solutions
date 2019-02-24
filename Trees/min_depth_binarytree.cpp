/*  Min depth of binary tree
    https://www.interviewbit.com/problems/min-depth-of-binary-tree/

    TC: O(n)
 */
int Solution::minDepth(TreeNode* root) {
    if(!root)
        return numeric_limits<int>::max();
        
    if(!root->left && !root->right)
        return 1;
        
    int l = minDepth(root->left);
    int r = minDepth(root->right);
        
    return min(l, r) + 1;
}
