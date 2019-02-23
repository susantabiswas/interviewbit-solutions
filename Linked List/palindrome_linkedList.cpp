/*
    Check if a linked list is palindrome
    https://www.interviewbit.com/problems/palindrome-list/
    TC: O(n)
    SC: O(n), function stack
 */

/*
    We use two pointers, one is used to go to till the last element and the
    other is pointing to head of list and starts moving once we reach the last node.
    At last node we compare the head value and current node value, then make the
    head pointer point to next node. 
 */
 bool isPalindrome(ListNode* head, ListNode*& head_iter) {
     if(!head)
        return true;
    
    // recurse till the last node        
    bool result = isPalindrome(head->next, head_iter);
    // non palindrome linkedlist
    if(!result)
        return false;
    // compare the current value with value from front of list
    if(head_iter->val == head->val) {
        // make the begining pointer point to next node
        head_iter = head_iter->next;
        return true;
    }
    else
        return false;
 }
 
int Solution::lPalin(ListNode* A) {
    ListNode* head_iter = A;
    return isPalindrome(A, head_iter);
}
