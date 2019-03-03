/**
 * Find the LCA of two nodes. Both the nodes might not be present also
 * https://www.interviewbit.com/problems/least-common-ancestor/
 * 
 * TC: O(n)
 */
 
TreeNode* findLCA(TreeNode* root, int& b, int& c, 
                    TreeNode*& first, TreeNode*& second) {
    if(!root)
        return nullptr;
    
    TreeNode* l = findLCA(root->left, b, c, first, second);
    TreeNode* r = findLCA(root->right, b, c, first, second);
    
    // if one node is in left subtree and other in right subtree and
    // this is the first parent to have that, this is the LCA
    if(l && r)
        return root;
    
    // if current node is equal to either of the nodes, that is the LCA
    // if they are in the same subtree
    if(root->val == b || root->val == c) {
        // if both node values are same
        if(b == c) {
            first = root;
            second = root;
        }
        else if(!first) {
            first = root;
        }
        else {
            second = root;
        }
        return root;
    }
    

    return l ? l : r;
}

int Solution::lca(TreeNode* root, int b, int c) {
    TreeNode* first = nullptr, *second = nullptr;
    TreeNode* lca = findLCA(root, b, c, first, second);
    
    // if both the nodes were found, then return lca or return -1
    return first && second ? lca->val : -1;
}
