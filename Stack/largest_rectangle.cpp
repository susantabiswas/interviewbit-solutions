/*
    Find the largest rectangle that can be formed from histogram
    https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/


/*
    Maximum area rectangle supported by a bar 'i' is bounded by the smaller
    bars on its left and right. So we use a stack and add current building to it
    if it is greater than all the buildings in stack. This ensures that the 
    closest building which might be smaller is always at the top.
    
    When a smaller building is encountered, we pop the stack buildings till the 
    top building is even smaller than current. This current building is right bound
    for all the popped buildings and their left bounds were the buildings before them
    in the stack.
*/
int Solution::largestRectangleArea(vector<int> &hist) {
    int max_area = numeric_limits<int> :: min();
    int curr_area = 0;
    int width = 0;
    
    stack<int> s;
    for(int i = 0; i < hist.size(); i++) {
        if(s.empty()) {
           s.emplace(i);
        }
        else if(hist[i] >= hist[s.top()]) { 
          s.emplace(i);
        }
        else if(hist[i] < hist[s.top()]) {  
            while(!s.empty() && hist[s.top()] > hist[i]) {
                int curr = s.top();
                s.pop();
                
                if(s.empty())
                    width = i;
                else
                    width = i - s.top() - 1;
                    
                curr_area = width * hist[curr];
                max_area = max(max_area, curr_area);
              
            }
            // push current
            s.emplace(i);
        }
    }

    // compute area for remaining bars
    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        if(s.empty())
            width = hist.size();
        else
            width = hist.size() - s.top() - 1;
            
        curr_area = width * hist[curr];
        max_area = max(max_area, curr_area);
    }
    return max_area;
}
