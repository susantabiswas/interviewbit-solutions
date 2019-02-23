/*
    Remove duplicate elements from linked list
    https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

    TC: O(n)
*/
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // if the list is empty
    if(!A)
        return nullptr;
        
    // keeps track of previous node
    ListNode* prev = nullptr;
    // new head and tail for distinct elements list
    ListNode* head = A;
    ListNode* tail = A;
    
    /* We traverse the list and each time check if the previous node
        value was same or not, if they are diff then the node is added to the new list
    */
    while(A) {
        // check with previous node value
        if(prev && prev->val != A->val){
            tail->next = A;
            tail = tail->next;
        }
        prev = A;
        A = A->next;
    }
    // make the last node of new list point to null to give proper termination
    tail->next = nullptr;
    return head;
}
