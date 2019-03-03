/**
 * Find two nodes in BST which equals K
 * https://www.interviewbit.com/problems/2sum-binary-tree/
 */

// Inorder of BST gives ascending ordered sequence when done left to right 
// and descending when done right to left. So we do inorder in both
// ways iteratively. Each time each of the ptrs will be pointing to the 
// smallest and largest element, if sum of those > k, we move the the right side
// traversal, if sum < k, we move the left side traversal and if sum == k, we have
// found two such nodes, return 1
int Solution::t2Sum(TreeNode* root, int k) {
    if(!root)
        return 0;
    
    // indicates which way traversal is allowed,
    // initially both are allowed
    bool left = true, right = true;
    
    stack<TreeNode*> s1, s2;
    TreeNode* l = root, *r = root;
    while(l || r || !s1.empty() || !s2.empty()) {
        // go left 
        while(left && l) {
            s1.emplace(l);
            l = l->left;
        }
        // go right
        while(right && r) {
            s2.emplace(r);
            r = r->right;
        }
        
        // if ascending traversal is allowed
        if(left) {
            l = s1.top();
            s1.pop();
        }
        
        // if descending traversal is allowed
        if(right) {
            r = s2.top();
            s2.pop();
        }
        
        // current sum
        int sum = l->val + r->val;
        
        // if nodes found on left and right side
        if(l == r)
            return 0;
        // sum found
        if(sum == k)
            return 1;
        // sum is lesser than k, do ascending traversal by one step
        else if(sum < k) {
            right = false;
            left = true;
            l = l->right;
        }
        // sum is greater, do descending traversal by one step
        else {
            left = false;
            right = true;
            r = r->left;
        }
    }
    
    return 0;
}
