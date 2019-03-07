/**
 * Copy a linked list with random pointers
 * https://www.interviewbit.com/problems/copy-list/
 */
 
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 


// Solution 2
RandomListNode* copyRandomLinkedList2(RandomListNode* head) {
    // create extra nodes after each node
    RandomListNode* it = head;
    while(it) {
        RandomListNode* node = new RandomListNode(it->label);
        node->next = it->next;
        it->next = node;
        
        it = (it->next)->next;
    }
    
    // set the random pointers
    it = head;
    RandomListNode* new_head = new RandomListNode(-1);
    RandomListNode* tail = new_head;
  
    while(it) {
        RandomListNode* random_ptr = it->random;
        // random node will be the next node of random node for old list
        if(random_ptr)
            (it->next)->random = random_ptr->next;
        
        it = it->next->next;
    }
    
    // revert the old list
    it = head;
    tail = new_head;
    while(it) {
        // add the copied pointer
        tail->next = it->next;
        tail = tail->next;
        
        it->next = (it->next)->next;
        it = it->next;
    }
    tail->next = nullptr;
    
    RandomListNode* t = new_head;
    new_head = new_head->next;
    delete t;
    
    return new_head;
}

// Solution 1
/*
    We use two hash tables:
        1. Node address to node index for old list
        2. Node index to address for new list
        
    So do one traversal creating the new list along with the two tables.
    Then do another traversal and set the random pointer for the new list
    using the two tables
*/
RandomListNode* copyRandomLinkedList1(RandomListNode* head) {
    // for mapping address of nodes of original list with their index in list
    unordered_map<RandomListNode*, int> addr_idx_old;
    // for mapping index of nodes with their address for new list
    unordered_map<int, RandomListNode*> idx_addr_new;
    
    // first create the second linked list and create the addr_idx_old table
    RandomListNode* it = head;
    // index of node
    int idx = 1;
    
    // head and tail for new list
    RandomListNode* new_head = new RandomListNode(head->label);
    RandomListNode* tail = new_head;
    addr_idx_old.emplace(head, idx);
    idx_addr_new.emplace(idx, new_head);
    ++idx;
    // since head has been copied, goto next
    it = it->next;
    
    while(it) {
        // copy node
        RandomListNode* node = new RandomListNode(it->label);
        
        // add address with index for old list
        addr_idx_old.emplace(it, idx);
        // add index with address for new list
        idx_addr_new.emplace(idx, node);
        ++idx;
        
        // add node to new list
        tail->next = node;
        tail = tail->next;
        
        it = it->next;
    }
    // end the new list
    tail->next = nullptr;
    
    // set the random pointer of new list
    RandomListNode* it1 = head, *it2 = new_head;
    
    while(it1) {
        RandomListNode* random_ptr = it1->random;
        
        if(random_ptr)
            it2->random = idx_addr_new[addr_idx_old[random_ptr]];
        
        // traverse further
        it1 = it1->next;
        it2 = it2->next;
    }
    
    return new_head;
}

RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    return copyRandomLinkedList1(head);
}
