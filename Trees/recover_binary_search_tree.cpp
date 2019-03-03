/**
 * Find swapped nodes in BST
 * https://www.interviewbit.com/problems/recover-binary-search-tree/
 * TC: O(n)
 */
 
/*
    There are two cases:
    1. swapped are adjacent 
    2. Swapped are not adjacent
    
    Another thing to note is first < second in inorder traversal, so
    first occurrence of finding a number greater than current, means that greater
    is one of the swapped numbers, we also save the next number in case this is adjacent case.
    Then when we find a number which is smaller than current, that would mean that is the
    first number , so this time the current smaller number is the second one. 
*/
void findSwappedNodes(TreeNode* root, TreeNode*& first, TreeNode*& second, 
                            TreeNode*& prev) {
    if(!root)
        return;
        
    findSwappedNodes(root->left, first, second, prev);
    // check if previous node is greater than current or not
    if(prev) {
        if(root->val < prev->val) {
            
            // if first number has been found, this should be second
            // and since first number is smaller than second, so it will
            // be smaller than the other numbers in sequence
            if(first) {
                second = root;
            }
            else {  // when this is the first number
                first = prev;
                // if the two swapped values are adjacent, so
                // save the second to be the current till we find another
                // anamoly, then that will be second
                second = root;
            }
        }
    }
    prev = root;
    findSwappedNodes(root->right, first, second, prev);
}

vector<int> Solution::recoverTree(TreeNode* root) {
    TreeNode* first = nullptr, *second = nullptr;
    TreeNode* prev = nullptr;
    findSwappedNodes(root, first, second, prev);
    
    vector<int> ans;
    ans.emplace_back(second->val);
    
    ans.emplace_back(first->val);
    
    return ans;
}
