/* https://www.interviewbit.com/problems/assign-mice-to-holes/

    Given mouse and hole positions. Find the minimum time required by the last
    mouse to reach its hole. Mouse can move left or right and each step is worth 1min
*/

// TC: O(nlogn)
// Sort both mouse positions and hole positions, 
// then we assign the mice i to hole i. While doing this
// keep track of mouse which takes the longest time to reach the hole
int Solution::mice(vector<int> &mices, vector<int> &locs) {
    if(mices.empty() || locs.empty())
        return 0;
    
    sort(mices.begin(), mices.end());
    sort(locs.begin(), locs.end());
    int max_time = 0;
    
    for(int i = 0; i<mices.size(); i++){
    if(max_time < abs(locs[i] - mices[i]) )
        max_time = abs(locs[i] - mices[i]);
    }
    
    return max_time;
}
