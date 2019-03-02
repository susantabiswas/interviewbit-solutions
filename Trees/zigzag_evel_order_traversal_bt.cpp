/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
    For left to right printing: pop from front and add children from left to right
    For right to left printing: pop from back and add children from right to left
    
*/
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return vector<vector<int>>{};

    vector<vector<int>> result;
    deque<TreeNode*> dq;
    dq.emplace_front(root);
    int level_nodes = dq.size();

    TreeNode* curr = nullptr;
    bool left_to_right = true;
    vector<int> curr_level;

    while (!dq.empty()) {
        //cout << dq.size() << endl;
        // when the direction is from left to right
        if (left_to_right) {
            curr = dq.front();
            dq.pop_front();
            curr_level.emplace_back(curr->val);

            if (curr->left)
                dq.emplace_back(curr->left);
            if (curr->right)
                dq.emplace_back(curr->right);
        }
        // when direction is from right to left
        else {
       
            curr = dq.back();
            dq.pop_back();
            curr_level.emplace_back(curr->val);

            if (curr->right)
                dq.emplace_front(curr->right);
            if (curr->left)
                dq.emplace_front(curr->left);
        }
      
        // if this is the last node of level,
        // change direction for next level
        --level_nodes;
        if (level_nodes <= 0) {
            result.emplace_back(move(curr_level));
            // change the direction
            left_to_right = !left_to_right;
            level_nodes = dq.size();
        }
    }

    return result;
}
