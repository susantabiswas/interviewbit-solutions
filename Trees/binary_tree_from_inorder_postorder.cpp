/**
 *  Create binary tree from inorder and postorder traversal data 
    https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

    TC: O(n)
 */
 
TreeNode* buildTreeInorderPostOrder(vector<int>& inorder, int in_start, int in_end,
                                vector<int>& postorder, int post_start, int post_end, 
                                                unordered_map<int, int>& inorder_map) {
    if(post_start > post_end)
        return nullptr;
        
    // current postorder start will be a root element
    TreeNode* root = new TreeNode(postorder[post_end]);
    // now we need to find the position of this rooot in inorder
    int inorder_pos = inorder_map[root->val];
    // find number of nodes in left and right subtree
    int left_nodes = inorder_pos - in_start;
    int right_nodes = in_end - inorder_pos;
    
    // create left and right subtrees
    root->left = buildTreeInorderPostOrder(inorder, in_start, inorder_pos - 1,
                        postorder, post_start, post_start + left_nodes - 1, inorder_map);
    
    root->right = buildTreeInorderPostOrder(inorder, inorder_pos + 1, in_end,
                        postorder, post_start + left_nodes, post_end - 1, inorder_map);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {

    // create a hash table mapping for inorder
    unordered_map<int, int> inorder_map;
    for(int i = 0; i < inorder.size(); i++)
        inorder_map[inorder[i]] = i;
    
    // In postorder traversal the root element is always at the and after subtree
    // we we start with back of traversal sequence and find that element in inorder
    // sequence and then left side is left subtree and right side will be right subtree
    int in_start = 0, in_end = inorder.size() - 1;
    int post_start = 0, post_end = postorder.size() - 1; 
    return buildTreeInorderPostOrder(inorder, in_start, in_end,
                            postorder, post_start, post_end, inorder_map);
    
}
