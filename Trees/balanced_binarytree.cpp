/* Check if binary tree is height balanced
    https://www.interviewbit.com/problems/balanced-binary-tree/

    TC: O(n)
*/

bool heightBalanced(TreeNode* root, int& h) {
    if(!root)
        return true;
        
    int lh = 0;
    int rh = 0;
    
    int l = heightBalanced(root->left, lh);
    int r = heightBalanced(root->right, rh);
    
    if(!l || !r)
        return false;
    // set current height
    h = max(lh, rh) + 1;
    
    if(abs(rh - lh) > 1)
        return false;
        
    return true;
}

int Solution::isBalanced(TreeNode* root) {
    int h = 0;
    return heightBalanced(root, h) ? 1 : 0;
}
