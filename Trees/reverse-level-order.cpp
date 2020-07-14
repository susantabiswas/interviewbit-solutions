/*
    https://www.interviewbit.com/problems/reverse-level-order/
    
    Since the final result will be reversed, so we do level order
    from right to left side.
    TC: O(N)
    SC: O(N)
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
vector<int> Solution::solve(TreeNode* root) {
    vector<int> result;
    
    queue<TreeNode*> q;
    q.emplace(root);
    
    while(!q.empty()) {
        auto curr = q.front(); 
        q.pop();
        result.emplace_back(curr->val);
        
        if(curr->right)
            q.emplace(curr->right);
        if(curr->left)
            q.emplace(curr->left);
    }
    
    reverse(result.begin(), result.end());
    return result;
}
