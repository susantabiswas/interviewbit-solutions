/*
    Insertion sort linked list
    https://www.interviewbit.com/problems/insertion-sort-list/

    TC: O(n)
*/

ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode* curr = head, *iter = nullptr;
    
    // start traversal
    while(curr) {
        
        // search for in sorted list which is greater than current,
        // swap values with it later
        iter = head;
        while(iter != curr && iter->val <= curr->val) {
            iter = iter->next;
        }
        
        // if the nodes before this are not sorted
        if(curr != iter) {
            // swap node values
            int temp = curr->val;
            curr->val = iter->val;
            iter->val = temp;
        }
        else    // all the nodes till current are sorted, so go to next node
            curr = curr->next;
    }
    
    return head;
}
