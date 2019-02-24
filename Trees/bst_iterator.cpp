/*
    BST iterator
    https://www.interviewbit.com/problems/bst-iterator/
*/

stack<TreeNode*> s;
TreeNode* curr = nullptr;

BSTIterator::BSTIterator(TreeNode *root) {
    // store the first few elements of DFS
    curr = root;
    while(curr) {
        s.push(curr);
        curr = curr->left;
    }
    
 //   while(hasNext())cout<<next();
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!s.empty() || curr)
        return true;
    else 
        return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    while(!s.empty() || curr) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        int smallest = curr->val;
        curr = curr->right;
        
        return smallest;
    }
    
    return -1;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
