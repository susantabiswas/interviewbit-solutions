/*
    https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Counts the no. of nodes 
// TC: O(N)
int getListCount(ListNode* head) {
    ListNode* iter = head;
    int c = 0;
    while(iter) {
        ++c;
        iter = iter->next;
    }
    return c;
}
// Creates a tree from linked list
// TC: O(N)
TreeNode* createBST(ListNode*& head, int num_nodes) {
    // no nodes
    if(!num_nodes)
        return nullptr;
        
    // create the root node
    TreeNode* root = new TreeNode(-1);
    // The idea is to create the tree from left side of list such that
    // both the sides are balanced and work up the way
    root->left = createBST(head, num_nodes/2);
    // give the value to root
    root->val = head->val;
    // goto to next node in list, this will become the next node
    // value in tree
    head = head->next;
    root->right = createBST(head, num_nodes - num_nodes/2 - 1);

    return root;
}
// SOLUTION 1
// TC: O(N), SC: O(1)
TreeNode* Solution::sortedListToBST(ListNode* head) {
    // Find the length of linked list
    int n_nodes = getListCount(head);
    return createBST(head, n_nodes);
}


/*
// TC: O(N), SC: O(N)
TreeNode* createBST(vector<int>& nodes, int start, int end) {
    if(start > end)
        return nullptr;
        
    // create the root node
    int middle = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nodes[middle]);
    root->left = createBST(nodes, start, middle-1);
    root->right = createBST(nodes, middle+1, end);
    return root;
} 

// SOLUTION 2
// TC: O(N), SC: O(N)
TreeNode* Solution::sortedListToBST1(ListNode* head) {
    vector<int> nodes;
    
    ListNode* tmp = head;
    while(tmp) {
        nodes.emplace_back(tmp->val);
        tmp = tmp->next;
    }
    return createBST(nodes, 0, nodes.size()-1);
}
*/
