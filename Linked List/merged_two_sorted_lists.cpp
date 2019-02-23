/* 
    Merge two sorted lists
    https://www.interviewbit.com/problems/merge-two-sorted-lists/

    TC: O(n)
*/

ListNode* Solution::mergeTwoLists(ListNode* head1, ListNode* head2) {
    // dummy head is just a starting node used to avoid writing code for
    // setting the head for first node of merged list
    ListNode* dummy_head = new ListNode(0);
    ListNode* head = dummy_head;
    
    while(head1 && head2) {
        if(head1->val < head2->val) {
            dummy_head->next = head1;
            head1 = head1->next;
        }
        else {
            dummy_head->next = head2;
            head2 = head2->next;
        }
        dummy_head = dummy_head->next;
    }
    // if one of the list still has elements append the nodes to the merged list
    dummy_head->next = head1 ? head1 : (head2 ? head2 : nullptr);
    
    ListNode* temp = head;
    head = head->next;
    delete temp;
    
    return head;
}
