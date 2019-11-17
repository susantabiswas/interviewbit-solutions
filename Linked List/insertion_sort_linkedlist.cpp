/*
    Insertion sort linked list
    https://www.interviewbit.com/problems/insertion-sort-list/

    TC: O(n)
*/
/*
    Solution 1: Nodes are swapped during sorting
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Inserts the node in its correct position to 
// keep the list still sorted
void insertSortedList(ListNode *&head, ListNode* node) {
    ListNode *prev = nullptr, *iter = head;
    while(iter) {
        // current node needs to be inserted here
        if(iter->val > node->val) 
            break;
        prev = iter;
        iter = iter->next;
    }
    prev->next = node;
    node->next = iter;
}

ListNode* Solution::insertionSortList(ListNode* head) {
    // head of sorted list
    ListNode *sorted_head = new ListNode(INT_MIN), *sorted_tail = nullptr;
    ListNode *iter = head, *prev = nullptr, *nextptr = nullptr;
    
    // traverse the nodes in list and put the
    // node in the sorted list created so far
    while(iter) {
        nextptr = iter->next;
        insertSortedList(sorted_head, iter);
        iter = nextptr;
    }
    // delete the dummy node
    ListNode* temp = sorted_head;
    sorted_head = sorted_head->next;
    delete temp;
    
    return sorted_head;
}


/*
    Solution 2: Only node values are swapped during sorting and not the nodes
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
