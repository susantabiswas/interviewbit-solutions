/**
 * Connect right siblings
 * https://www.interviewbit.com/problems/next-pointer-binary-tree/
 */
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.emplace(root);
    
    TreeLinkNode* prev = nullptr, *curr = nullptr;
    int level_count = q.size();
    
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        --level_count;
        
        if(prev)
            prev->next = curr;
        
        if(curr->left)
            q.emplace(curr->left);
        if(curr->right)
            q.emplace(curr->right);
        
        prev = curr;
        
        if(level_count == 0) {
            level_count = q.size();
            prev = nullptr;
        }
    }
}
