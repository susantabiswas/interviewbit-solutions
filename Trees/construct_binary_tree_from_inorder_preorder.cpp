/**
 * Construct binary tree from inorder and preorder sequence
 * https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
 * TC: O(n)
 */
 
TreeNode* buildTreePreorderInorder(vector<int>& inorder, int in_start, int in_end,
                                vector<int>& preorder, int pre_start, int pre_end, 
                                                unordered_map<int, int>& inorder_map) {
    if(pre_start > pre_end)
        return nullptr;
        
    // create the root node
    TreeNode* root = new TreeNode(preorder[pre_start]);
    // now we need to find the position of this root in inorder
    int inorder_pos = inorder_map[root->val];
    // find number of nodes in left and right subtree
    int left_nodes = inorder_pos - in_start;
    int right_nodes = in_end - inorder_pos;
    
    root->left = buildTreePreorderInorder(inorder, in_start, inorder_pos - 1, preorder,
                            pre_start + 1, pre_start + left_nodes, inorder_map);
    root->right = buildTreePreorderInorder(inorder, inorder_pos + 1, in_end, preorder,
                            pre_start + left_nodes + 1, pre_end, inorder_map);
    return root;
}
                                                
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    
    // create a hash table mapping for inorder
    unordered_map<int, int> inorder_map;
    for(int i = 0; i < inorder.size(); i++)
        inorder_map[inorder[i]] = i;
        
    // Preorder traversal first gives root of a subtree, we find the position of 
    // this root in inorder, then recurse on left and right side of inorder list 
    // for finding the left and right subtree
    int in_start = 0, in_end = inorder.size() - 1;
    int pre_start = 0, pre_end = preorder.size() - 1;
    
    return buildTreePreorderInorder(inorder, in_start, in_end, preorder, 
                    pre_start, pre_end, inorder_map);
}
