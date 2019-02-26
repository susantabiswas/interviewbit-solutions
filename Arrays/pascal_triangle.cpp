/*
    Pascal triangle
    https://www.interviewbit.com/problems/pascal-triangle/

    TC: O(n^2)
*/

vector<vector<int> > Solution::solve(int n) {
    if(n <= 0)
        return vector<vector<int>>{};
    vector<vector<int>> result(n);

    // start with the first row 
    result[0].emplace_back(1);

    // generate the remaining n-1 rows
    for(int i = 1; i < n; i++) {
        // first push the first element
        result[i].emplace_back(1);

        // fill the remaining positions using sum from previous level
        for(int j = 1; j < i; j++) {
            result[i].emplace_back(result[i-1][j-1] + result[i-1][j]);
        }
        // push the last element
        result[i].emplace_back(1);
    }    
    return result;
}
