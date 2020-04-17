/* 
    https://www.interviewbit.com/problems/bulbs/

    Find min no. of flips for turning all elements to 1
    On flipping 'i' all elements on right of it are flipped
*/

/*
    We keep track of no. of switches made and 
    for each bulb, we check what the status of the bulb
    after all those switches, if it is OFF again switch is applied and
    continue.
    TC: O(1)
*/
int Solution::bulbs(vector<int> &arr) {
    // for keeping track of nu of switch flips used
    int flips = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        // check what the final state for current 
        // position after applying the flips till now
        // when odd no of flips are made, the state changes
        bool flipped = flips % 2 == 0 ? false : true;
        int curr_state = flipped ? !arr[i] : arr[i];
        // if the state after flipping is OFF, again switch
        if(curr_state == 0)
            ++flips;
    }
    return flips;
}


// TC: O(n)
/*
    Flipping is required whenever there is a zero element.
    Now no. of times flipping needs to be done depends on how many
    times the adjacent elements change.
    
    Traverse starting from the first zero element and check the right
    side, if the element differs that means on flipping the current
    element the right side element will be inversed so we again need
    to flip that element when we reach that. So we count no. of such
    occurences
*/
int Solution::bulbs(vector<int> &arr) {
    // check if the there zero bulbs
    if(arr.empty())
        return 0;
        
    int flips = 0;
    
    // traverse till the first zero element
    int i = 0;
    for(i = 0; i < arr.size() && arr[i] != 0; i++);
    
    for(; i < arr.size()-1; i++){
        if(arr[i] != arr[i+1])
            ++flips;
    }
    
    // if the no. of flips is zero but the vector is filled with only zero
    // 1 flip is required, if filled with 1, then 0 flips.
    // if no. of flips is zero and there is mix of 0s and 1s, then ans is flip + 1
    // to account for the first zero element
    return flips == 0 ? i == arr.size() - 1? 1 : 0 : flips + 1;
}
