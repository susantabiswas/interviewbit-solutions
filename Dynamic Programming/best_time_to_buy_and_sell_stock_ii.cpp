/*

    Buy and sell stock when there is no restriction on number of times to buy
    https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
*/

int Solution::maxProfit(const vector<int> &arr) {
    if(arr.empty())
           return 0;
    
    int max_profit = 0;
    
    // whenever we get to buy a stock for cheap and sell for a higher 
    // price we will do it
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i+1] > arr[i])
            max_profit += arr[i+1] - arr[i];
    }
    return max_profit;
}
