/*
    https://www.interviewbit.com/problems/two-out-of-three/
    
    To check common elements, we find the common elements in A with B and C.
    B with C, this ensures that this will detect all common elements.
    Next we use hash table for storing A and B elements. We use the hash tables 
    to find the common elements.
    
    TC: O(a + b + c)
    SC: O(a + b + c)
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    
    unordered_set<int> elements_a, elements_b, common_elements;
    
    // unique elements of A
    for(auto &el: A)
        if(elements_a.count(el) == 0) 
            elements_a.emplace(el);
        
    for(auto &el: B) {
        // unique elements of B
        if(elements_b.count(el) == 0) { 
            elements_b.emplace(el);
        }
        // check if current element exists in A
        if(elements_a.count(el)) 
            common_elements.emplace(el);
    }
        
    for(auto &el: C) {
        // check if current element exists in B
        if(elements_b.count(el)) { 
            common_elements.emplace(el);
        }
        // check if current element exists in A
        if(elements_a.count(el)) 
            common_elements.emplace(el);
    }
    
    vector<int> result(common_elements.begin(), common_elements.end());
    sort(result.begin(), result.end());
    return result;
}
