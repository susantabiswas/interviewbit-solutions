/* 
    reverse only subpart of list
    https://www.interviewbit.com/problems/reverse-link-list-ii/

    TC: O(n)
*/


// reverses a linked list
ListNode* reverse(ListNode* head) {
    ListNode* next_ptr = nullptr, *prev = nullptr;
    while(head) {
        // save next node addrs
        next_ptr = head->next;
        // reverse current node
        head->next = prev;
        prev = head;
        // go to next node
        head = next_ptr;
    }
    return prev; 
}

ListNode* Solution::reverseBetween(ListNode* head, int start, int end) {
    
    //  if there is only one node
    if(!head->next)
        return head;
    ListNode* prev = nullptr, *node_before_start = nullptr, *node_after_end = nullptr,
            *new_head = nullptr, *new_end = nullptr;
    ListNode* iter = head;
    int c = 0;
    
    // traverse the list and separate the list from start-to-end
    while(iter) {
        ++c;
        // if this is startiing node
        if(c == start) {
            node_before_start = prev;
            new_head = iter;
        }
        // if this is the ending node
        if(c == end) {
            new_end = iter;
            break;
        }
        // stores the previous node for next node
        prev = iter;
        // traverse further
        iter = iter->next;
    }
    // save the addr of node which will be next to
    // the reversed list end
    node_after_end = new_end->next;
    
    // separate the list
    if(node_before_start)
        node_before_start->next = nullptr;
    new_end->next = nullptr;
    // reverse the sublist
    ListNode* reversed_head = reverse(new_head);
    // connect the sublist back
    if(node_before_start)
        node_before_start->next = reversed_head;
    else 
        head = reversed_head;
    new_head->next = node_after_end;
    
    return head;
}
