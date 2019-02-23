/* 
    https://www.interviewbit.com/problems/bulbs/

    Find min no. of flips for turning all elements to 1
    On flipping 'i' all elements on right of it are flipped
*/


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
