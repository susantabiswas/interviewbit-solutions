/*
    https://www.interviewbit.com/problems/sort-binary-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) {
    ListNode *one = new ListNode(-1), *zero = new ListNode(-1);
    ListNode *one_tail = one, *zero_tail = zero;
    ListNode *curr = head;
    
    while(curr) {
        if(curr->val == 0) {
            zero_tail->next = curr;
            zero_tail = zero_tail->next;
        }
        else {
            one_tail->next = curr;
            one_tail = one_tail->next;
        }
        curr = curr->next;
    }
    // end the lists
    zero_tail->next = nullptr, one_tail->next = nullptr;
    // Stitch the lists
    zero_tail->next = one->next;
    ListNode *sorted_head = zero->next ? zero->next : one->next;
    delete one, delete zero;
    
    return sorted_head;
}
