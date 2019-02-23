/* 
    https://www.interviewbit.com/problems/reorder-list/
    TC: O(n)
*/

// for reversing the linked list
ListNode* reverseList(ListNode* head) {
    if(!head)
        return nullptr;
        
    ListNode* prev = nullptr;
    ListNode* next_ptr = nullptr;
    
    while(head) {
        next_ptr = head->next;
        head->next = prev;
        prev = head;
        head = next_ptr;
    }
    return prev;
}


// for cutting the list in half
void cutListInHalf(ListNode* head, ListNode*& head1, ListNode*& head2) {
    if(!head) {
        head1 = nullptr, head2 = nullptr;
        return;
    }
        
    ListNode* slow = head, *fast = head, *prev = nullptr;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // set the first list
    head1 = head;
    // set the second list
    // if there are even nodes, then list ends at n/2th node
    head2 = fast == nullptr ? prev->next : slow->next;
    // end the first list
    if(fast == nullptr)
        prev->next = nullptr;
    else
        slow->next = nullptr;
}

// for merging the list in alternate format
ListNode* mergeInAlternateFashion(ListNode* head1, ListNode* head2) {
    if(!head2)
        return head1;
        
    ListNode* iter1 = head1, *iter2 = head2;
    ListNode* merged_tail = nullptr;
    ListNode* next_ptr = nullptr;
    
    while(iter1 && iter2) {
        // save next node of list 1
        next_ptr = iter1->next;
        
        // first node in merged list
        if(!merged_tail) {
            merged_tail = iter1;
        }
        else {
            // add the first node
            merged_tail->next = iter1;
            // point tail to currently added node
            merged_tail = merged_tail->next;
        }
        
        // add the second node
        merged_tail->next = iter2;
        // point tail to last node
        merged_tail = merged_tail->next;
        
        // traverse both the list further
        iter1 = next_ptr;
        iter2 = iter2->next;
    }
    
    // if there still node left in list 1
    if(iter1) {
        // since this will be the last node
        iter1->next = nullptr;
        merged_tail->next = iter1;
    }
    return head1;
}


ListNode* Solution::reorderList(ListNode* head) {
    
    ListNode* head1 = nullptr, *head2 = nullptr;
    // split list in half, if odd nodes are there, list1 will have 1 more node
    cutListInHalf(head, head1, head2);
    head2 = reverseList(head2);
   
    return mergeInAlternateFashion(head1, head2);
}
