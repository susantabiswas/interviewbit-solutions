/*
    https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
    
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    vector<int> level;
    deque<TreeNode*> q;
    q.emplace_back(root);
    
    bool left = true;
    int n_level = q.size();
    TreeNode *curr = nullptr;
    
    while(!q.empty()) {
        // when we traverse from left side
        // We add the siblings in left to right order
        if(left) {
            curr = q.front();
            q.pop_front();
            
            if(curr->left)
                q.emplace_back(curr->left);
            if(curr->right)
                q.emplace_back(curr->right);
        }    
        // when we traverse from right side, we add
        // siblings from right to left order in front 
        // of queue, so that for the next left traversal
        // the last node's children comes first in left to right order
        else {
            curr = q.back();
            q.pop_back();
            
            if(curr->right)
                q.emplace_front(curr->right);
            if(curr->left)
                q.emplace_front(curr->left);
        }
        level.emplace_back(curr->val);
        --n_level;
        
        if(n_level == 0) {
            // reverse the direction
            left = !left;
            n_level = q.size();
            result.emplace_back(move(level));
        }
    }
    return result;
}
