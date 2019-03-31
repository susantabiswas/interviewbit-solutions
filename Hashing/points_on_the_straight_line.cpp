/*
  Given n points, find the max points lying on a straight line.
  https://www.interviewbit.com/problems/points-on-the-straight-line/
*/

int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    if(x.size() == 0)
        return 0;
        
    unordered_map<double, int> slope;
    
    int max_pts = 1;
    
    // find the slope for line starting with ith coordinate
    for(int i = 0; i < x.size(); i++) {
        int curr_pts = 0;
        int same = 0;
        int vertical = 0;
            
        slope.clear();
        for(int j = i+1; j < x.size(); j++) {
            // either current coordinate is same
            // as starting  or form a line with it
            // only when the coordinates are diff
            // find the slope and store it
            double y_comp = (y[j] - y[i]);
            double x_comp = (x[j] - x[i]);
            
            // same point
            if(x_comp == 0 && y_comp == 0) {
                ++same;
            }
            else {
                // if vertical line
                if(x_comp == 0) {
                    ++vertical;
                }
                else {
                    // slope 
                    double m = (1.0) * (y_comp / x_comp);
                    if(slope.find(m) == slope.end())
                        slope.emplace(m, 1);
                    else
                        ++slope[m];
                    curr_pts = max(curr_pts, slope[m]);
                }
            }
        }
        max_pts = max(max_pts, curr_pts + 1 + same);
        max_pts = max(max_pts, vertical + 1 + same);
    }
    
    return max_pts;
}
