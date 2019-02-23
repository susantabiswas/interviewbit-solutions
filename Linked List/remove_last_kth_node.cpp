/*
    Remove kth node from end of list
    https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

    TC: O(n)
*/

ListNode* Solution::removeNthFromEnd(ListNode* head, int k) {
    if(!head || k < 0)
        return nullptr;
    if(k == 0)
        return head;
        
    ListNode* iter1 = head, *iter2 = head, *prev = nullptr;
    // keeping track of count
    int c = 1;
    // first traverse till Kth node
    while(iter1->next && c++ < k)
        iter1 = iter1->next;
        
    // if the iterating ptr has reached list end, but that is lesser
    // than K, means list is smaller than K, so remove first node
    if(!iter1->next && c != k) {
        // remove head
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    // start iter2, by the time iter1 reaches end of list, iter2 will be 
    // at k-1 position
    while(iter1->next) {
        iter1 = iter1->next;
        prev = iter2;
        iter2 = iter2->next;
    }
    // 1st node needs to be removed
    if(!prev) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        // remove the Kth node
        prev->next = iter2->next;
        delete iter2;
    }
    return head;
}
