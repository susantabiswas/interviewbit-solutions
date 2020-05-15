/*
    Check if list is cyclic
    https://www.interviewbit.com/problems/list-cycle/
*/

ListNode* Solution::detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = (fast->next)->next;
        
        // if the two nodes meet
        if(slow == fast)
            break;
    }
    
    // cycle is present
    if(slow == fast) {
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    return slow == fast ? slow : nullptr;
}
