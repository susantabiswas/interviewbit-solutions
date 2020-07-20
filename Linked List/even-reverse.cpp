/*
    https://www.interviewbit.com/problems/even-reverse/
    
    TC: O(N)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverseList(ListNode *head) {
    ListNode *curr = head, *prev = nullptr, *nextptr = nullptr;
    while(curr) {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

ListNode* Solution::solve(ListNode* head) {
    // separate the even and odd lists
    ListNode *odd = new ListNode(-1), *even = new ListNode(-1);
    ListNode *odd_tail = odd, *even_tail = even;
    ListNode *curr = head;
    int idx = 1;
    
    while(curr) {
        if(idx % 2 != 0) {
            odd_tail->next = curr;
            odd_tail = curr;
        }   
        else {
            even_tail->next = curr;
            even_tail = curr;
        }
        idx += 1;
        curr = curr->next;
    }
    odd_tail->next = nullptr, even_tail->next = nullptr;
    // reverse the even list
    ListNode *dummy = even;
    even = even->next;
    delete dummy;
    dummy = odd;
    odd = odd->next;
    delete dummy;
    
    even = reverseList(even);
    
    // merge the list
    ListNode *result = new ListNode(-1);
    ListNode *tail = result;
    
    while(odd) {
        tail->next = odd;
        odd = odd->next;
        
        tail = tail->next;
        tail->next = even;
        tail = tail->next;
        
        if(even)
            even = even->next;
    }
    
    return result->next;
}
