/*
    https://www.interviewbit.com/problems/all-factors/
    
    TC: O(sqrt(N))
*/
vector<int> Solution::allFactors(int num) {
    if(num == 1 || num == 0)
        return num == 1 ? vector<int>{1} : vector<int>{};
        
    int limit = floor(sqrt(num));
    vector<int> result;
    
    for(int i = 1; i <= limit; i++)
        if(num % i == 0) {
            result.emplace_back(i);
            // only add the other factor if they are not same
            // to avoid adding the sqrt(N) twice, eg: 169: 13 * 13
            if((num / i) != i)
                result.emplace_back(num / i);
        }
    sort(result.begin(), result.end());
    return result;
}
