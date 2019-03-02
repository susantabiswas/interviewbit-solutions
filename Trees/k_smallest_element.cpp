/*
    Find the kth smallest element in a Binary tree
    https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

    TC: O(n)
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
bool findKSmallest(TreeNode* root, int& k_smallest, int& curr_c, int& k) {
    if(!root)
        return false;
    
    if(findKSmallest(root->left, k_smallest, curr_c, k))
        return true;
    ++curr_c;
    if(curr_c == k) {
        k_smallest = root->val;
        return true;
    }
    if(findKSmallest(root->right, k_smallest, curr_c, k))
        return true;;
}

int Solution::kthsmallest(TreeNode* root, int k) {
    int k_smallest = 0;
    int curr_c = 0;
    findKSmallest(root, k_smallest, curr_c, k);
    
    return k_smallest;
}
