/*
    Preorder traversal
    https://www.interviewbit.com/problems/preorder-traversal/

    TC: O(n)
    SC; O(h)
 */

void doPreorderTraversal(TreeNode* root, vector<int>& preorder) {
    if(root) {
        preorder.emplace_back(root->val);
        doPreorderTraversal(root->left, preorder);
        doPreorderTraversal(root->right, preorder);
    }
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    doPreorderTraversal(root, preorder);

    return preorder;
}
