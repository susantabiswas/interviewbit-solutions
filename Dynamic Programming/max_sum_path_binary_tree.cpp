/**
 * Maximum sum path in binary tree
 * https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
 */

// for each node we find the maximum path sum including that node.
// maximum can be either that node alaone, node + left/right child
// or the path from left + root + right , then we return the max path
// till current node to its parent node and continue
int findMaxPathSum(TreeNode* root, int& max_sum) {
    if(!root)
        return 0;
    
    int l = findMaxPathSum(root->left, max_sum);
    int r = findMaxPathSum(root->right, max_sum);
    
    int max_child_sum = max(l, r);
    // path including current node with maximum of either child
    int max_till_root = max(max_child_sum + root->val, root->val);
    // path from left to right child
    int max_with_left_right = max(max_till_root, l + r + root->val);
    
    max_sum = max(max_sum, max_with_left_right);
    
    // return the maximum path sum including current node
    return max_till_root;
}

int Solution::maxPathSum(TreeNode* root) {
    int max_sum = numeric_limits<int> :: min();
    
    findMaxPathSum(root, max_sum);
    return max_sum;
}
