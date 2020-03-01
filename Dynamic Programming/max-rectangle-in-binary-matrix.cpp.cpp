/*
    https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
    Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
*/

// finds the largest rectangle in histogram
int largestHistogramRectangle(vector<int>& heights) {
    stack<int> s;
    int max_area = 0, curr_area = 0;
    const int N = heights.size();
    
    for(int i = 0; i < N; i++) {
        // if current height is a limiting height
        while(!s.empty() && heights[i] <= heights[s.top()]) {
            int curr = s.top();
            // pop the current height
            s.pop();
            curr_area = heights[curr] * (i - (s.empty() ? 0 : s.top() + 1));
            max_area = max(max_area, curr_area);
        }
        s.emplace(i);
    }
    // pop the remaining heights
    while(!s.empty()) {
        int curr = s.top();
        // pop the current height
        s.pop();
        curr_area = heights[curr] * (N - (s.empty() ? 0 : s.top() + 1));
        max_area = max(max_area, curr_area);
    }
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &grid) {
    if(grid.empty())
        return 0;
    int max_area = 0;
    const int M = grid.size(), N = grid[0].size();
    vector<int> heights(N, 0);
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            // if current cell has 0, column height becomes 0
            heights[j] = grid[i][j] == 0 ? 0 : heights[j] + 1;
        max_area = max(max_area, largestHistogramRectangle(heights));
    }
    return max_area;
}
