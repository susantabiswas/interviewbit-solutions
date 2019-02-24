/*
    Check if two trees are identical
    https://www.interviewbit.com/problems/identical-binary-trees/
    
    TC: O(n)
    SC: O(h)
*/


int Solution::isSameTree(TreeNode* root1, TreeNode* root2) {

    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
        
    return (root1->val == root2->val) &&
            isSameTree(root1->left, root2->left) &&
            isSameTree(root1->right, root2->right);
}
