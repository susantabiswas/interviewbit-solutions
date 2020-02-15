/* Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 

Return the numbers in sorted order.
*/

/*
    We can do this using BFS.
    The idea is to start with initial digits 1-9, then each time
    for the next state, add a new digit in the LSB. This new LSB should be
    curr_lsb +1, curr_lsb-1.
    
    TC: 9 + 9*2 + 9*3 + ..... 9n
        =9(1+2+3....n)
        =O(n^2)
    n: no. of digits in upper limit M
    
*/

// Using BFS
vector<int> Solution::stepnum(int n, int m) {
    queue<int> q;
    vector<int> stepping_nums;
    
    // Initial MSB
    for(int i = 1; i <= 9; i++)
        q.emplace(i);
        
    while(!q.empty()) {
        // For the current number, the next stepping number can be
        // reached by adding a digit in the LSB pos. which will current LSB-1 and LSB+1.
        // 21->212, 213
        int curr = q.front();
        q.pop();
        
        if(curr >= n && curr <= m)
            stepping_nums.emplace_back(curr);
        
        // ensure that the next number is lesser than upper range
        if(curr <= m /10 ) {
            int lsb = curr % 10;
            int lsb_less = 0, lsb_more = 0;
            // if lsb is 0, do only LSB +1
            if(lsb != 0) {
                lsb_less = curr * 10 + (lsb - 1);
                q.emplace(lsb_less);
            }
            // if the LSB is 9, we only do LSB-1 for the new LSB
            // also ensure that the new number is smaller than upper range
            if(lsb != 9 && (curr * 10 <= m - (lsb+1))) {
                lsb_more = curr * 10 + (lsb + 1);
                q.emplace(lsb_more);
            }
        }
        
    }
    
    // if range starts from 0, add zero
    if(n == 0)
        stepping_nums.insert(stepping_nums.begin(), 0);
    return stepping_nums;
}

/* 
    Solution 2: Non graph solution
    TC: O((m-n)*L), L: length of longest number
*/
vector<int> Solution::stepnum(int A, int B) {
    vector<int> result;
    int prev = -11;
    int num;
    bool stepping_num = true;
    
    for(int i = A; i <= B; i++){
        stepping_num = true;
        num = i;
        prev = num % 10;
        num /= 10;
        while(num){
            if(abs((num%10) - prev) != 1){
                stepping_num = false;
                break;
            }
            else{
                prev = num % 10;
                num = num / 10;
            }
        }
        
        if(stepping_num)
            result.emplace_back(i);
    }
    
    return result;
}
