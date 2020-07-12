/*
    https://www.interviewbit.com/problems/profit-maximisation/
    
    Since we want to maximize profit, we pick the row with the
    most number of vacant seats. So we use a max heap to keep track of vacant 
    seats which can make max profit. Once a seat from a largest vacant seats
    row is used, we insert vacant-1 number of seats in heap.
    
    TC: O(bloga)
*/
int Solution::solve(vector<int> &arr, int b) {
    long long profit = 0;
    priority_queue<int, vector<int>, less<>> 
        max_heap(arr.begin(), arr.end());
    
    while(b--) {
        int seats = max_heap.top();
        max_heap.pop();
        profit = profit + seats;
        // add the new count of vacant seats in the current row
        max_heap.emplace(seats - 1);
    }
    return profit;
}
