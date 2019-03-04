/*
    Given a string representing row in a theatre with occupied and vacant seats. Find the min jumps required
    to bring everyone together.
    https://www.interviewbit.com/problems/seats/

    TC: O(n)
*/

/*
    The closest distance for every occupant to cover will be the median seat position.
    SO we find the median seat number and then calculate the jumps required for the
    occupants sitting on the left and right side of median seat position.
*/
int Solution::seats(string str) {
    int i= 0;
    
    // find the median of occupied seats
    vector<int> median;
    for(int i = 0; i < str.size(); i++)
        if(str[i] == 'x')
            median.emplace_back(i);
     // when there are only 1 or 0 occupants      
    if(median.size() <= 1)
        return 0;
    
    // find the median seat number
    int mid = 0;
    // odd number of occupants
    if(median.size() % 2 != 0)
        mid = median[median.size() / 2];
    else
        mid = (median[median.size() / 2] + median[(median.size() / 2) - 1]) / 2; 
   
    int jumps = 0;
    
    // starting empty seat for left 
    int l_seat = mid;
    i = mid;
    while(i >= 0) {
        if(str[i] == 'x') {
            jumps = jumps % 10000003 + abs(l_seat - i) % 10000003;
            --l_seat;
        }
        --i;
    }
    
    int r_seat = mid + 1;
    i = mid + 1;
    while(i < str.size()) {
        if(str[i] == 'x') {
            jumps = jumps % 10000003 + abs(r_seat - i) % 10000003;
            ++r_seat;
        }
        ++i;
    }
    
    return jumps % 10000003;
}
