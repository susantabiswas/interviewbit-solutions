/*
    Remove nodes with duplicates
    https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

    
*/
/*
    TC: O(n)
    SC: O(n) 
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if(!head)
        return nullptr;
        
    ListNode* iter = head, *prev = nullptr, *curr = nullptr;
    ListNode *dummy_head = new ListNode(0), *tail = dummy_head;
    int c = 0;
    
    while(iter) {
        c = 0;
        curr = iter;
        // traverse till the node is not equal to current node
        // and keep count how many times current appears
        while(curr && curr->val == iter->val) {
            ++c;
            curr = curr->next;
        }
        
        // if current node is distinct
        if(c == 1) {
            // add to new list
            tail->next = iter;
            tail = tail->next;
        }
        // move the current pointer to next candidate pointer
        iter = curr;
    }
    
    // ptr to dummy node
    ListNode* temp = dummy_head;
    // end the list
    tail->next = nullptr;
    // point to real head
    dummy_head = dummy_head->next;
    // delete the duumy node
    delete temp;
    
    return dummy_head;
    return nullptr;
}

/*
    TC: O(n)
    SC: O(n)
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    unordered_map<int, int> h;
    
    // take the count for each node
    ListNode* iter = head;
    while(iter) {
        if(h.find(iter->val) != h.end()) {
            ++h[iter->val];
        }
        else 
            h[iter->val] = 1;
        
        iter = iter->next;
    }
    
    // again do one traversal, adding node which appears only once
    ListNode* dummy_head = new ListNode(0);
    ListNode* tail = dummy_head;
    iter = head;
    while(iter) {
        // add the node only if it exists once
        if(h[iter->val] == 1) {
            tail->next = iter;
            tail = tail->next;
        }
        iter = iter->next;
    }
    // end the new list
    tail->next = nullptr;
    
    // delete the first dummy node and return the head
    iter = dummy_head;
    dummy_head = dummy_head->next;
    delete iter;
    
    return dummy_head;
}
