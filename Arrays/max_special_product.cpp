/* 
    https://www.interviewbit.com/problems/maxspprod/
    TC: O(n)
    SC: O(n)
*/
int Solution::maxSpecialProduct(vector<int> &arr) {
    long long max_product = 0;
    long long product = 0;
    stack<long long>s;
    
    vector<long long > left_product(arr.size(), 0);
    // forward pass: We just want to have max element which is nearest.
    // So if current element is greater then no need for previous greater 
    // element, pop till top is greater.
    for(long long i = 0; i < arr.size(); i++) {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        left_product[i] = s.empty() ? 0 : s.top();
        // push current element index
        s.emplace(i);
    }
    
    while(!s.empty())
        s.pop();
        
    vector<long long> right_product(arr.size(), 0);
    // backward pass
    for(long long i = arr.size() - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        // find special product for current
        right_product[i] = s.empty() ? 0 : s.top();
        // push the current element index
        s.emplace(i);
    }
    for(int i = 0; i < arr.size(); i++) {
        product = left_product[i] * right_product[i];
        max_product = max(max_product, product);
    }
    return max_product % 1000000007;
}
