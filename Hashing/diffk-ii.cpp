/*
    https://www.interviewbit.com/problems/diffk-ii/
    
    TC: O(N), SC: O(N)
*/
int Solution::diffPossible(const vector<int> &nums, int target) {
    unordered_set<int> s;
    
    for(const int& num: nums) {
        // a - b = target
        // when we have 'a', search for target + b
        // when we have 'b', search for -(target - a) 
        if(s.find(-1 * (target - num)) != s.end() ||
            s.find(target + num) != s.end()) 
            return 1;
        s.emplace(num);
    }
    return 0;
}
