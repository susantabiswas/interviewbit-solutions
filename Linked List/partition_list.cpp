/* 
    Partiton linked list acc. to pivot
    https://www.interviewbit.com/problems/partition-list/
    TC: O(n) 
*/ 
// Inserts the node in the passed list
void insertNode(ListNode*& head, ListNode*& tail, ListNode* node) {
    // first node of the list
    if(!head) {
        head = node;
        tail = node;
        return; 
    }
    
    // append the new node at the back 
    tail->next = node;
    // update the tail pointer and make its next null
    tail = tail->next;
    tail->next = nullptr;
}

ListNode* Solution::partition(ListNode* head, int pivot) {
    ListNode *iter = head, *nextptr = nullptr;
    // heads and tails of lesser and greater nodes lists wrt pivot
    ListNode *lesser_head = nullptr, *lesser_tail = nullptr;
    ListNode *greater_head = nullptr, *greater_tail = nullptr;
    
    // traverse the list and based on the value of each node
    // append them to lesser or greater side
    while(iter) {
        nextptr = iter->next;
        if(iter->val < pivot)
            insertNode(lesser_head, lesser_tail, iter);
        else 
            insertNode(greater_head, greater_tail, iter);
            
        iter = nextptr;
    }
    
    // join the smaller and larger nodes list
    if(lesser_head) 
        lesser_tail->next = greater_head;
    
    // if there are no lesser nodes list, then return the greater nodes list
    return lesser_head ? lesser_head : greater_head;
}
