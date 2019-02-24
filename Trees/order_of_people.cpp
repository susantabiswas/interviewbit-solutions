/*
    https://www.interviewbit.com/problems/order-of-people-heights/
 */

struct Height{
    int h;
    int infront;
    
    bool operator<(const Height& b) const {
        return h < b.h;
    }
};

/*
    TC: O(n^2)
    Sort heights
    starting with the smallest height, check how many infront are required
    , then start traversing from index 0 of resultant array and check  if there
    are required number of infront positions avail for taller people to come before
    current height, then place the current height once that criteria is met.
*/
vector<int> Solution::order(vector<int> &h, vector<int> &front) {
    vector<Height> heights;
    vector<int> result(h.size(), -1);
    
    for(int i = 0; i < h.size(); i++) {
        heights.emplace_back(Height{h[i], front[i]});
    }
    sort(heights.begin(), heights.end());
    
    for(int i = 0; i < heights.size(); i++) {
        int infront = heights[i].infront;
        for(int j = 0; j < result.size(); j++) {
           if(infront == 0 && result[j] == -1) {
                result[j] = heights[i].h;
                break;
            }
            else if(result[j] == -1)
                --infront;
        }
    }
    return result;
}
