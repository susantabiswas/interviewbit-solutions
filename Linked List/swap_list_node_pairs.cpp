/*
    Swap list nodes in pairs
    https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
    TC: O(n)
*/

// reverses a linked
ListNode* Solution::swapPairs(ListNode* head) {
    ListNode* it = head;
    ListNode* prev = nullptr, *next_ptr = nullptr, *tail = nullptr;
    // update the head value
    head = head->next ? head->next : head;
    while(it && it->next) {
        prev = it->next;
        // ptr to first node of next pair
        next_ptr = it->next->next;
        // make the previous list tail point to second node
        if(tail)
            tail->next = it->next;
        // make the second node point to first node
        it->next->next = it;
        // connect the first node with the next node in list
        it->next = next_ptr;
        // set the tail for current pair
        tail = it;
        // go to first node of next pair
        it = next_ptr;
    }
    
    return head;
}
