/**
 * Merge K sorted linked lists.
 * https://www.interviewbit.com/problems/merge-k-sorted-lists/
 */
 
/*
    This can be done in two ways:
    1. Using heaps: Make K sized max heap with head ptrs of each list,
                    then pop the smallest node, add that to the sorted list, push its 
                    next node to heap if that is not null
                    
                TC: O(nlogk), n: total no. of nodes
                
    2. Using Merging of two list at a time:
        We merge lists in pairs, then again merge the new merged lists in pair untill
        no more pairs can be formed
        
        TC: O(nlogk), where n: length of longest list, which is equal to total no. of nodes
*/

// Using Heaps
ListNode* mergeKListsHeaps(vector<ListNode*> arr) {
    priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>>
        pq([](const ListNode* a, const ListNode* b)->bool{
            return a->val > b->val;
        });
    
    // now add the head ptrs of each list
    for(const auto& head: arr) {
        if(head)
            pq.emplace(head);
    }
    
    // dummy head
    ListNode* new_head = new ListNode(-1);
    ListNode* tail = new_head;
    ListNode* curr = nullptr;
    
    // start merging
    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        
        // add the current smallest node to sorted list
        tail->next = curr;
        // update tail ptr
        tail = tail->next;
        
        // add the next node of popped list
        curr = curr->next;
        if(curr)
            pq.emplace(curr);
    }
    // end the list
    tail->next = nullptr;
    
    // delete the dummy head
    ListNode* t = new_head;
    new_head = new_head->next;
    delete t;
    return new_head;
}

// Merge two given linked lists
ListNode* mergeList(ListNode* head1, ListNode* head2) {
    if(!head1 || !head2)
        return head1 ? head1 : head2;
        
    // we use a dummy node which prevents writing code for first head update etc.
    ListNode* dummy_head = new ListNode(-1);
    ListNode* tail = dummy_head;
    
    ListNode *it1 = head1, *it2 = head2;
    
    // traverse the two list and merge on the go 
    while(it1 && it2) {
        if(it1->val < it2->val) {
            tail->next = it1;
            // goto to next in list1
            it1 = it1->next;
        }    
        else {
            tail->next = it2;
            it2 = it2->next;
        }
        
        // update tail node value    
        tail = tail->next;
        tail->next = nullptr;
    }
    
    // if one of the lists still has nodes left
    tail->next = it1 ? it1 : it2;
    
    // delete the dummy head
    ListNode* temp = dummy_head;
    dummy_head = dummy_head->next;
    delete temp;
    
    return dummy_head;
}

ListNode* mergeLinkedLists(vector<ListNode*>& arr, int l, int h) {
    return nullptr;  
}

void disp(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeKLinkedLists(vector<ListNode*>& arr) {
    ListNode* prev_head = nullptr;
    ListNode* curr_head = nullptr;
    for(int i = 0; i < arr.size(); i += 2) {
        if((i+1) < arr.size()) {
            curr_head = mergeList(arr[i], arr[i + 1]);
            curr_head = mergeList(curr_head, prev_head);
        }
        else 
            curr_head = mergeList(arr[i], prev_head);
            
        prev_head = curr_head;
    }
    
    return curr_head;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &arr) {
    // using heap
   // ListNode* heap_merged = mergeKListsHeaps(arr);
    
    // using normal merging
    ListNode* classic_merged = mergeKLinkedLists(arr);
     
    return classic_merged;
}
