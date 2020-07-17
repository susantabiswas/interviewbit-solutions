/*
    https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/
    
    We track the diff odd count frequencies using a hash table.
    Look for current odd count - B in the hash table.
    TC: O(N)
    SC: O(N)
*/
int Solution::solve(vector<int> &arr, int B) {
    int odd_count = 0, subarrays = 0;
    // (odd count, number of positions ending with the count)
    unordered_map<int, int> pos;
    
    // empty array has 0 odd numbers
    pos[0] = 1;
    for(int i = 0; i < arr.size(); i++) {
        // check if the current number is odd or not
        odd_count = odd_count + (arr[i] % 2 != 0);
        // now check if there is a subarray ending at current pos. 
        // with B odd numbers
        if(pos.count(odd_count - B))
            subarrays += pos[odd_count - B];
        ++pos[odd_count];
    }
    return subarrays;
}
