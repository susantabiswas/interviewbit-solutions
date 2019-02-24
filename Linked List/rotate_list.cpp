/*
    Rotate list by k 
    https://www.interviewbit.com/problems/rotate-list/

    TC: O(n)
*/
// get count of total number of nodes
int getCount(ListNode* head) {
    int c = 0;
    while(head) {
        head = head->next;
        ++c;
    }
    return c;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(!head || !head->next)
        return head;
    
    ListNode* iter = head, *list_end = nullptr;
    int c = 0;
    
    // count number of nodes in list
    int node_count = getCount(head);
    // find what is the true number of shifts required
    k = k % node_count;
    // if number of shifts is just a multiple of total nodes
    if(k == 0)
        return head;
    
    // traverse till last node and store addr of k-1th node
    while(iter->next) {
        ++c;
        // if this is k-1th node
        if(c == node_count - k) {
            list_end = iter; 
        }
        iter = iter->next;
    }
    
    ListNode* new_head = list_end->next;
    iter->next = head;
    list_end->next = nullptr;
    
    return new_head;
}
