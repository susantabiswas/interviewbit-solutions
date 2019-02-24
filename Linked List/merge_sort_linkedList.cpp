/**
 *  Merge sort linked list
 * https://www.interviewbit.com/problems/sort-list/
 * 
 * TC: O(nlogn)
 */

// for merging two sorted lists
ListNode* mergeSortedLists(ListNode* head1, ListNode* head2) {
    ListNode* dummy_head = new ListNode(0), *tail = dummy_head;
    
    while(head1 && head2) {
        if(head1->val < head2->val) {
            tail->next = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            head2 = head2->next;
        }
        
        // go to last node
        tail = tail->next;
    }
    
    // if any of the list is remaining, append it,
    // if both are finished, then nullptr will be appended
    tail->next = head1 ? head1 : head2;
    
    // delete the dummy node
    ListNode* temp = dummy_head;
    dummy_head = dummy_head->next;
    delete temp;
    
    return dummy_head;    
}

ListNode* findMiddle(ListNode* head) {
    if(!head || !head->next) 
        return head;
        
    ListNode* slow = head, *fast = head, *prev = nullptr;
    
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev;
}

ListNode* mergeSortLinkedList(ListNode* head) {
    if(!head || !head->next)
        return head;
    
    // finds the floor(n/2)th node
    ListNode* middle = findMiddle(head);
    // split the current list in half
    // second list head
    ListNode* second_list = middle->next;
    // end the first list
    middle->next = nullptr;
    return mergeSortedLists(mergeSortLinkedList(head), mergeSortLinkedList(second_list));
}

ListNode* Solution::sortList(ListNode* head) {
    return mergeSortLinkedList(head);
}
