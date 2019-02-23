/*
    Add two numbers represented as linked list
    https://www.interviewbit.com/problems/add-two-numbers-as-lists/

    TC: O(max(n, m))
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* num1, ListNode* num2) {
    int carry = 0;
    int data = 0;
    ListNode* iter1 = num1, *iter2 = num2;
    ListNode* dummy_head = new ListNode(0);
    ListNode* tail = dummy_head;
    
    // add digits till one of them runs out of digits
    while(iter1 && iter2) {
        data = carry + iter1->val + iter2->val;
        tail->next = new ListNode(data % 10);
        tail = tail->next;
        carry = data / 10;
        
        // go to next digit
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    
    // if either of the numbers still have some digits left
    ListNode* iter = iter1 ? iter1 : iter2;
    while(iter) {
        data = carry + iter->val;
        tail->next = new ListNode(data % 10);
        tail = tail->next;
        carry = data / 10;
        
        iter = iter->next;
    }
    
    // if carry is still left
    if(carry) {
        tail->next = new ListNode(carry);
    }
    
    ListNode* temp = dummy_head;
    dummy_head = dummy_head->next;
    delete temp;
    
    return dummy_head;
}
