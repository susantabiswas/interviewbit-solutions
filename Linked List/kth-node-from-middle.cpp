/*
    https://www.interviewbit.com/problems/kth-node-from-middle/
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
int countNodes(ListNode *head) {
    int c = 0;
    while(head) {
        head = head->next;
        ++c;
    }
    return c;
}

int Solution::solve(ListNode* head, int B) {
    int n_nodes = countNodes(head);
    int mid_node_idx = n_nodes / 2 + 1;
    
    if(B < mid_node_idx) {
        int nodes_to_move = mid_node_idx - 1 - B;
        while(head && nodes_to_move-- > 0)
            head = head->next;
        return head->val;
    }
    return -1;
}
