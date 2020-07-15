/*
    https://www.interviewbit.com/problems/path-to-given-node/
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
bool findPath(TreeNode* root, int& B, 
            vector<int> partial, vector<int>& path) {
    if(!root)
        return false;
    
    // add the current node in path
    partial.emplace_back(root->val);
    // if the node is found
    if(root->val == B) {
        path = move(partial);
        return true;
    }
    return findPath(root->left, B, partial, path) || 
            findPath(root->right, B, partial, path);
}

vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> path;
    findPath(root, B, {}, path);
    return path;
}
