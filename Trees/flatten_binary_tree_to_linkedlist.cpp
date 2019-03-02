/**
 * Convert a binary tree to linked list
 * https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
 * 
 * TC: O(n)
 */
 
/*
    We do preorder traversal, changing the previous node on the go
*/
TreeNode* treeToList(TreeNode* root, TreeNode*& prev) {
    if(!root)
        return nullptr;
    
    // save the right pointer, because during left traversal right child value
    // will change, so for doing right tree traversal this is required
    TreeNode* r = root->right;
    // make the previous preorder node flat
    if(prev) {
        prev->left = nullptr;
        prev->right = root;
    }
    // update prev 
    prev = root;
    treeToList(root->left, prev);
    treeToList(r, prev);
    return root;
}

TreeNode* Solution::flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    return treeToList(root, prev);
}
