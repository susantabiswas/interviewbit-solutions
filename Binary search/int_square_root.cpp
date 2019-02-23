/* find the Integer square root of a number
    https://www.interviewbit.com/problems/square-root-of-integer/
 */
int Solution::sqrt(int a) {
    if(a <= 1)
        return a;
        
    int left = 1, right = a;
    
    while(left <= right) {
        int middle = left + (right - left) / 2;
        
        // when the root is found
        if(middle == a / middle) {
            return middle;
        }
        // when the middle is greater, change right limit
        else if(middle > a / middle) {
            right = middle - 1;
        } // when middle is smaller change left limit
        else {
            // we know that middle is smaller for sure, so 
            // incrementing left by middle + 1, ensures
            // that even if updated left is bigger than 'a'
            // our previous left is the closest value for 'a'
            left = middle + 1;
        }
        
    }
    return left - 1;
}
