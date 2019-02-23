/*
    Check if list is cyclic
    https://www.interviewbit.com/problems/list-cycle/
*/

ListNode* Solution::detectCycle(ListNode* head) {
    // We will use Floyd's algorithm for this
    ListNode* slow = head, *fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // if the two pointers meet, means cycle is present
        if(slow == fast) {
            break;
        }
    }
    
    // cycle is present, find the cycle start
    if(fast == slow) {
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    else
        return nullptr;
}
