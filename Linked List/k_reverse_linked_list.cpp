/**
 * Reverse k nodes at a time in a linked list
 * https://www.interviewbit.com/problems/k-reverse-linked-list/
 * O(k * (n / k))
 */

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

ListNode* Solution::reverseList(ListNode* head, int k) {
    if(!head)
        return nullptr;
    
    ListNode* it = head;
    // we use two pointers to store the head and tail of k sized list
    ListNode* start = head, *prev = nullptr;
    int c = 0;
    ListNode* new_head = nullptr;
    
    // first time when the list is reversed head is changed
    while(it) {
        ++c;
        prev = it;
        it = it->next;
        // k nodes traversed, reverse those nodes
        if(c == k) {
            // separate the list
            prev->next = nullptr;
            new_head = reverseLinkedList(start);        
            // join the tail node of reversed list
            start->next = it;
            break;
        }
    }
  
    // now we will reverse the remaining k sized list
    c = 0;
    // save the tail pointer of last k sized list,
    // this will be used to connect the next reversed list
    ListNode* prev_list_tail = start;
    //ListNode* nextptr
    start = it;
    while(it) {
        ++c;
        prev = it;
        it = it->next;
        // k nodes traversed, reverse those nodes
        if(c == k) {
            c = 0;
            // separate the list
            if(prev)
                prev->next = nullptr;
            // join the previous list with current
            prev_list_tail->next = reverseLinkedList(start);
            // save the tail ptr of current list
            prev_list_tail = start;
            // join the tail node of reversed list
            // now the start pointer is the tail of reversed list,
            // make it point to next node 
            start->next = it;
            // next k sized list head
            start = it;
        }
      
    }
    
    
    return new_head;
}
