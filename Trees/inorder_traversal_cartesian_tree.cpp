/**
 * Build tree from inorder cartesian tree traversal
 * https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
 * 
 * TC: O(n^2)
 */
 
/*
    The root is always going to be the largest element in the range. So
    we find the largest element, then recurse on its left and right subarray
    for left and right subtree respectively.
*/
// finds the max element
int getMax(vector<int>& arr, int& l, int& h) {
    int max_idx = l;
    for(int i = l; i <= h; i++) {
        if(arr[max_idx] < arr[i])
            max_idx = i;
    }
    return max_idx;
}

TreeNode* buildTreeFromCartesianTraversal(vector<int>& arr, int l, int h) {
    if(l > h)
        return nullptr;
    
    // find the max element that will be the current root
    int max_idx = getMax(arr, l, h);

    // create root node
    TreeNode* root = new TreeNode(arr[max_idx]);
    root->left = buildTreeFromCartesianTraversal(arr, l, max_idx - 1);
    root->right = buildTreeFromCartesianTraversal(arr, max_idx + 1, h);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &arr) {
    return buildTreeFromCartesianTraversal(arr, 0, arr.size() - 1);
}
