/*
    https://www.interviewbit.com/problems/pairs-with-given-xor/
    
    Since we are looking for x^y = B, so to do this in 
    linear time, we use a hash table where we push the elements
    as we move. For the current element we check if there was any
    element seen in the past which we can get with B ^ y. This works because
    XOR is commutative and distributive.
    
    TC: O(N)
    SC: O(M)
*/
int Solution::solve(vector<int> &arr, int B) {
    unordered_set<int> elements;
    int pairs = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        // check if there is any number whose XOR 
        // can give B
        if(elements.count(B ^ arr[i])) 
            ++pairs;
        elements.emplace(arr[i]);
    }
    return pairs;
}
