/*
    https://www.interviewbit.com/problems/diagonal-traversal/
    
    Looking at the problem carefully, it is evident that for every left move
    we move to a lower line and for right move we move across the same line.
    So we use numeric values starting with 0 for root and for all the nodes,
    we add them to the vector for their numeric slope value.
    
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
void traversal(TreeNode* root, int slope,
            vector<vector<int>>& lines) {
    if(!root)
        return;
    // if this is the first pt on the line
    if(lines.size() <= slope)
        lines.emplace_back(vector<int>{});  
    // add the current node to its appropriate line
    lines[slope].emplace_back(root->val);
    
    traversal(root->left, slope+1, lines);
    traversal(root->right, slope, lines);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int> result;
    vector<vector<int>> lines;
    traversal(root, 0, lines);
    
    for(auto line: lines) 
        result.insert(result.end(), line.begin(), line.end());
    return result;
}
