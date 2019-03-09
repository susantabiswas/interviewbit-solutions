/*
    Buy and sell stock once
    https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
*/

int Solution::maxProfit(const vector<int> &arr) {
    if(arr.size() < 1)
        return 0;
    // max profit encountered so far
    int max_profit = numeric_limits<int> :: min();
    // min stock encountered till current stock inclusive of current
    int min_stock = numeric_limits<int> :: max();
    
    // for each day, we find the profit that can be earned if
    // stock is sold on that day
    for(int i = 0; i < arr.size(); i++) {
        min_stock = min(min_stock, arr[i]);
        max_profit = max(arr[i] - min_stock, max_profit);
    }
    
    return max_profit;
}
