/*
    Find the max rectangle in a binary matrix.
    https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
*/
// finds the area of largest rectangle in histogram
int findLargestHistogramArea(vector<int> heights) {
    int max_area = 0;
    int idx = -1;
    int curr_area = 0;
    
    stack<int> buildings;
    
    for(int i = 0; i<heights.size(); i++){
        // if the height of the current building is higher 
        if(buildings.empty() || heights[buildings.top()] < heights[i]){
            buildings.push(i);
        }
        else if(heights[buildings.top()] >= heights[i]){    // when the current height is shorter
            
            // pop the buildings and at the same time compute the largest area for each
            while(!buildings.empty() && heights[buildings.top()] >= heights[i]){
                // compute area for the current building
                idx = buildings.top();
                buildings.pop();
                // area of largest rectangle supported by this building
                curr_area = heights[idx] * (i - (buildings.empty() ? 0 : buildings.top()+1));
                if(curr_area > max_area){
                    max_area = curr_area;
                }
            }
            
            // push the current building
            buildings.push(i);
        }
    }
    
    // area for the remaining buildings
    while(!buildings.empty()){
        idx = buildings.top();
        buildings.pop();
        
        curr_area = heights[idx] * (heights.size() - (buildings.empty() ? 0 : buildings.top()+1));
        if(curr_area > max_area)
            max_area = curr_area;
    }
    
    return max_area;
}

int findMaxRectangleArea(vector<vector<int> >& mat, vector<vector<int> >& dp) {
    int max_area = numeric_limits<int> :: min();
    
    // 1st row
    for(int i = 0; i < mat[0].size(); i++)
        dp[0][i] = mat[0][i];
    
    max_area = findLargestHistogramArea(dp[0]);    
    // we compute the column wise area for the remaining positions
    for(int i = 1; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            // if the current element is 1, then only it can be part of
            // column rectangle
            if(mat[i][j]) {
                dp[i][j] += dp[i-1][j] + 1;
            }
        }
        int curr_area = findLargestHistogramArea(dp[i]);
        // now we consider the row as a histogram and find the
        // largest rectangle in this histogram
        max_area = max(max_area, curr_area);
    }
    
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &mat) {
    if(mat.size() == 0)
        return 0;
        
    vector<vector<int> > dp(mat.size(), vector<int>(mat[0].size(), 0));
    
    int max_area = findMaxRectangleArea(mat, dp);
    
    return max_area;
}
