/*
    Inorder tree traversal
    https://www.interviewbit.com/problems/inorder-traversal/
    TC: O(n)
    SC: O(h)
*/

void doInorderTraversal(TreeNode* root, vector<int>& inorder) {
    if(root) {
        doInorderTraversal(root->left, inorder);
        inorder.emplace_back(root->val);
        doInorderTraversal(root->right, inorder);
    }
}

vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    doInorderTraversal(root, inorder);

    return inorder;
}
