/**
 * Subtarct second half of list from first half
    https://www.interviewbit.com/problems/subtract/
    TC: O(n)
*/

// recursive solution
bool subtractFirstLast(ListNode* head, ListNode*& head_ptr) {
    // reached the end of the list
    if(!head)
        return false;
        
    // first recurse till the end
    if(subtractFirstLast(head->next, head_ptr))
        return true;
    // check if the first and last ptr are same or not, for odd length
    // list they stop at the middle node
    if(head == head_ptr) {
        return true;
    }
    else {
        // subtract : last node value from first node
        head_ptr->val = head->val - head_ptr->val;  
        // make the first pt go to next node
        head_ptr = head_ptr->next;
        
        // if the list has even number of elements, so we need to check 
        // if next of head_ptr is the current head value, otherwise
        // they won't stop and the subtraction will be done for remaining half also
        if(head_ptr == head)
            return true;
    }
    return false;
}

// reverses the linked list 
ListNode* reverseLinkedList(ListNode* head) {
    if(!head)
        return nullptr;
       
    ListNode* it = head, *prev = nullptr, *next_ptr = nullptr;
    while(it) {
        next_ptr = it->next;
        // reverse the node
        it->next = prev;
        // update previous node value
        prev = it;
        // tarverse further
        it = next_ptr;
    }
    
    return prev;
}

/*
    Reverse the list from middle point, then start traversal from head and 
    from after the middle node, which is actually now the last node.
    Do subtraction till starting node is not equal to next node of middle
    
    Then revert back the list
*/
ListNode* Solution::subtract(ListNode* head) {
    if(!head ||!head->next)
        return head;
        
    ListNode* fast = head, *slow = head, *prev = nullptr;
    // find the middle point
    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    // reverse the list after middle node
    prev->next = reverseLinkedList(slow);
    
    // start doing subtraction calculation
    ListNode* it = prev->next, *start = head; 
    while(start != prev->next) {
        start->val = it->val - start->val;
        start = start->next;
        it = it->next;
    }
    
    //revert back the list
    prev->next = reverseLinkedList(prev->next);
    return head;
}
