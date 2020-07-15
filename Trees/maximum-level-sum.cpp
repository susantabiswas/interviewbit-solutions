/*
    https://www.interviewbit.com/problems/maximum-level-sum/
    
    We do BFS  and calculate the level wise sum. We keep track of
    max sum.
    TC: O(N)
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
int Solution::solve(TreeNode* root) {
    int max_sum = 0, level_sum = 0;
    queue<TreeNode*> q;
    q.emplace(root);
    int n_level = q.size(), level = 1;
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        level_sum += curr->val;
        --n_level;
        
        if(curr->left)
            q.emplace(curr->left);
        if(curr->right)
            q.emplace(curr->right);
        
        // current level has ended, compare the 
        // current levels with max sum
        if(n_level == 0) {
            ++level;
            n_level = q.size();
            max_sum = max(max_sum, level_sum);
            level_sum = 0;
        }
    }
    
    return max_sum;
}
