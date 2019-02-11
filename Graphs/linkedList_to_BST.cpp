/* 
https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

Given a sorted linkedlist, convert it to a height balanced BST
*/

/* Solution 2 : without extra space*/
// TC: O(n), SC: O(1)
TreeNode* convertToTree2(int n, ListNode*& head){
    if(n == 0)
        return nullptr;
    
    // create a new node and initialise with 0 for now
    TreeNode* node = new TreeNode(0);

    // recurse for left subtree
    node->left = convertToTree2(n/2, head);
    
    // now set the data value
    node->val = head->val;
    
    // the idea is to make the head point to the
    // element which should be if done inorder traversal
    // so make head point to the next node 
    head = head->next;
    
    // right subtree
    node->right = convertToTree2(n - n/2 - 1, head);

    return node;
}

TreeNode* solution2(ListNode* head){
    if(!head)
        return nullptr;
    // count no. of nodes
    ListNode* temp = head;
    int node_count = 1;
    
    while(temp){
        ++node_count;
        temp = temp->next;
    }
    
    return convertToTree2(node_count-1, head);
}

/* Solution 1 */
// TC: O(n), SC: O(n)
TreeNode* convertToTree1(vector<ListNode*>& linkedlist, int l, int h){
    if(l > h)
        return nullptr;
    
    int middle = l + (h-l)/2;
    // create node with middle element
    TreeNode* node = new TreeNode(linkedlist[middle]->val);
    node->val = linkedlist[middle]->val;
    
    node->left = convertToTree1(linkedlist, l, middle-1);
    node->right = convertToTree1(linkedlist, middle+1, h);
    
    return node;
}

TreeNode* solution1(ListNode* A){
    if(!A)
        return nullptr;
    vector<ListNode*> linkedlist;
    
    // make a indexed representation of list elements
    ListNode* temp = A;
    while(temp){
        linkedlist.emplace_back(temp);
        temp = temp->next;
    }

    return convertToTree1(linkedlist, 0, linkedlist.size()-1);
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
   return  solution2(A);
}
