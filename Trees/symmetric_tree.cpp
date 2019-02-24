/* 
check if tree is symmetric
    https://www.interviewbit.com/problems/symmetric-binary-tree/
    TC: O(n)
    SC: O(h)
 */


bool isTreeSymmetric(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
        
    return (root1->val == root2->val) &&
            isTreeSymmetric(root1->left, root2->right) &&
            isTreeSymmetric(root1->right, root2->left);
}

int Solution::isSymmetric(TreeNode* root) {
    return isTreeSymmetric(root->left, root->right) ? 1 : 0;
}
