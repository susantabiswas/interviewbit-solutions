/*
    postorder traversal 
    https://www.interviewbit.com/problems/postorder-traversal/

    TC: O(n)
    SC: O(h)
*/


void doPostorderTraversal(TreeNode* root, vector<int>& postorder) {
    if(root) {
        doPostorderTraversal(root->left, postorder);
        doPostorderTraversal(root->right, postorder);
        postorder.emplace_back(root->val);
    }
}

vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    doPostorderTraversal(root, postorder);

    return postorder;
}