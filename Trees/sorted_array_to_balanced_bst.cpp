/**
 * Convert an array to min height balanced tree
 * https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
 * 
 * TC: O(n)
 */

// To have the min height diff, no. of elements on each side should
// be almost equal, so every time we make the middle element as root
TreeNode* arrayToHeightBalancedTree(const vector<int> &arr, int l, int h) {
    // when no elements left
    if(l > h)
        return nullptr;
    // when only one node left, this will become a leaf node
    if(l == h)
        return new TreeNode(arr[l]);
        
    // make the middle element as root
    int middle = l + (h - l) / 2;
    TreeNode* root = new TreeNode(arr[middle]);
    
    // connect its left and right child
    root->left = arrayToHeightBalancedTree(arr, l, middle - 1);
    root->right = arrayToHeightBalancedTree(arr, middle + 1, h);
    
    return root;
    
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &arr) {
    return arrayToHeightBalancedTree(arr, 0, arr.size() - 1);   
}
