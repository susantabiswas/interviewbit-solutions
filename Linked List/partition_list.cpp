/* 
    Partiton linked list acc. to pivot
    https://www.interviewbit.com/problems/partition-list/
    TC: O(n) 
*/

ListNode* Solution::partition(ListNode* head, int pivot) {
    if(!head)
        return nullptr;
        
    ListNode* iter = head;
    // we will maintain two lists: smaller and greater(contains equal too)
    ListNode* smaller = nullptr, *greater = nullptr;
    ListNode* tail_smaller = nullptr, *tail_greater = nullptr;
  while(iter) {
        // when data is lesser than pivot
        if(iter->val < pivot) {
            if(smaller == nullptr) {
                smaller = iter;
                tail_smaller = smaller;
            }
            else {
                tail_smaller->next = iter;
                tail_smaller = tail_smaller->next;
            }
        }
       else {   // current data >= pivot 
            if(greater == nullptr) {
                greater = iter;
                tail_greater = greater;
            }
            else {
                tail_greater->next = iter;
                tail_greater = tail_greater->next;
            }
        }
        // traverse to next node
        iter = iter->next;
    }
  
    // end the three lists
    if(tail_smaller)
        tail_smaller->next = nullptr;
    if(tail_greater)
        tail_greater->next = nullptr;
        
   // choose a suitable head for partitioned list
    ListNode* partitioned_head = smaller ? smaller : 
                                    ( greater ? greater : nullptr);
    
    // now append the two lists: smaller->greater
    if(smaller) 
        tail_smaller->next = greater ? greater : nullptr;
        
    return partitioned_head;
}
