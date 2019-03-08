/*
    Anti diagonal printing
    https://www.interviewbit.com/problems/anti-diagonals/
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &arr) {
    const int N = arr.size();
    vector<vector<int>> result;
    vector<int> partial;
    
    if(N <= 1)
        return arr;
    
    // 1st half
    for(int i = 0; i < N; i++) {
        int col = i;
        int row = 0;
        while(col >= 0 && row < N) {
            partial.emplace_back(arr[row][col]);
            --col;
            ++row;
        }
        result.emplace_back(move(partial));
    }
    // 2nd half: always start row 2nd row
    for(int i = 1; i < N; i++) {
        int col = N - 1;
        int row = i;
        while(col >= 0 && row < N) {
            partial.emplace_back(arr[row][col]);
            --col;
            ++row;
        }
        result.emplace_back(move(partial));
    }
    return result;
}
