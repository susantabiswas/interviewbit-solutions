/**
 *  Path sum from root to leaf
    https://www.interviewbit.com/problems/path-sum/

    TC: O(n)
 */
int Solution::hasPathSum(TreeNode* root, int sum) {
    if(!root)
        return 0;
    
    // subtract current data
    sum = sum - root->val;
    //cout<<"sum:"<<sum<<endl;
    // leaf node
    if(!root->left && !root->right)
        return sum == 0;
    
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
