/**
 * Find the sum all the numbers formed from root to leaf
 * https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
 * TC: O(n)
 */

// finds the sum of all root to leaf numbers 
void findRootLeafNumberSum(TreeNode* root, long long curr_num, long long& total) {
    if(!root)
        return;
    
    // add the current digit
    curr_num = (curr_num * 10 + root->val) % 1003;
    // leaf node
    if(!root->left && !root->right) {//cout<<curr_num<<endl;
        // add current path number
        total = total + (curr_num) % 1003;
        return;
    }
    
    findRootLeafNumberSum(root->left, curr_num, total);
    findRootLeafNumberSum(root->right, curr_num, total);
}

int Solution::sumNumbers(TreeNode* root) {
    long long total = 0, curr_num = 0;
    findRootLeafNumberSum(root, curr_num, total);
    return total % 1003;
}
