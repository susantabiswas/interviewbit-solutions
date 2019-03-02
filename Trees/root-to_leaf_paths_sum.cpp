/*
    Given a sum, find all root to leaf paths
    https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
*/
 
// finds all the root to leaf paths for a given sum
void findSumPaths(TreeNode* root, int sum, vector<int> curr_path,
                    vector<vector<int>>& result) {
    if(!root)
        return;
    
    sum -= root->val;
    curr_path.emplace_back(root->val);
    
    // if current is a leaf node
    if(!root->left && !root->right && sum  == 0) {
        result.emplace_back(move(curr_path));
        return;
    }
    findSumPaths(root->left, sum, curr_path, result);
    findSumPaths(root->right, sum, curr_path, result);
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> curr_path;
    findSumPaths(root, sum, curr_path, result);
    
    return result;
}
