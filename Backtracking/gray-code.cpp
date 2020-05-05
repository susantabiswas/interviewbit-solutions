/*
    Find n bits gray code sequence.
    https://www.interviewbit.com/problems/gray-code/
*/
// SOLUTION 1
/*
    For a given sequence of gray codes, if we put the same sequence in reverse order
    after the original sequence, the entire sequence is again a gray code except for the
    boundary number or the last number of original gray codes. Now if 1 is prepended
    in front of each of the reverse sequence numbers then all the numbers stay unique 
    and the gray code order is also maintained.
*/
vector<int> Solution::grayCode(int n) {
    if(n == 1)
        return vector<int>{0,1};
    
    vector<int> result = {0, 1, 3, 2};
    int shift = 2;
    // we already have answer for n=2
    n -= 2;
    
    while(n--) {
        // prepend 1 to the all the numbers, starting from
        // the backside
        int n_nums = result.size();
        for(int i = n_nums-1; i >= 0; i--) {
            result.emplace_back(1 << shift | result[i]);
        }
        ++shift;
    }
    return result;
}

////////////////////////////////

// SOLUTION 2
/*
    Since each nbit number is actually all n-1 bits numbers with 0 and 1 in 
    front. So if we have calculated gray code for say of 2 bits, then gray code
    sequence for 3 bits will be 0 and 1 prepended with the gray code of 2 bits.
    The second half with 1 in front will have the reverse of sequence of n-1 bits gray code
*/
vector<int> Solution::grayCode(int n) {
    int curr = n;
    int num = 0;
    set<int> s;
    
    if(n == 1)
        return vector<int>{0, 1};
        
    vector<int> initial = {0, 1, 3, 2};
    vector<int> result;
    
    int shift_length = 2;
    n = n - 2;
    while(n--) {
        int prev_seq_size = initial.size();
        // prepend 0 in beginning
        for(int i = 0; i < prev_seq_size; i++) {
            result.emplace_back(0 << shift_length | initial[i]);
        }
        
        // prepend 1 in beginning
        for(int i = prev_seq_size - 1; i >= 0; i--) {
            result.emplace_back(1 << shift_length | initial[i]);
        }
        
        ++shift_length;
        initial = move(result);
    }
    
    return initial;
}
