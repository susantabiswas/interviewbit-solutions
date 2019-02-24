/* 
    Connect right siblings
    https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
    TC: O(n)

*/

void Solution::connect(TreeLinkNode* root) {
    if(!root)
        return;
        
    queue<TreeLinkNode*> q;
    
    q.emplace(root);
    TreeLinkNode* prev = nullptr, *curr = nullptr;
    int level_nodes = q.size();
    
    while(!q.empty())  {
        curr = q.front();
        q.pop();
        --level_nodes;
        
        // add the child nodes
        if(curr->left)
            q.emplace(curr->left);
        if(curr->right)
            q.emplace(curr->right);
            
        // set the next ptr of previous node in current level
        if(prev) {
            prev->next = curr;
        }
        
        prev = curr;
        
        // last node of current level
        if(level_nodes == 0) {
            // set no. of nodes for next level
            level_nodes = q.size();
            prev = nullptr;
        }
    }
}
