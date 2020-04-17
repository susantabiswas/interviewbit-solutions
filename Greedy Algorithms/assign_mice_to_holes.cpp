/* https://www.interviewbit.com/problems/assign-mice-to-holes/

    Given mouse and hole positions. Find the minimum time required by the last
    mouse to reach its hole. Mouse can move left or right and each step is worth 1min
*/

/*
    Sort the arrays in ascending order. Now once sorted, for each ith mice the closest
    hole position will also be at hole[i], this is because they are sorted
    and any mice after current mice if it wants to go hole[i], for it that will
    take more time than mice[i], as position wise this comes at ith number in order.
    
    TC: O(NlogN)
*/
int Solution::mice(vector<int> &mice, vector<int> &holes) {
    // sort the positions
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int max_time = 0;
    
    for(int i = 0; i < mice.size(); i++) 
        max_time = max(max_time, abs(holes[i] - mice[i]));
    return max_time;
}


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
