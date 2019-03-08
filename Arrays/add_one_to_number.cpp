/*  
    Add to number in array form
    https://www.interviewbit.com/problems/add-one-to-number/
*/

vector<int> Solution::plusOne(vector<int> &arr) {
    int i = arr.size() - 1;
    int carry = 1;
    arr[i] += 1;
    
    // for every digit we update its previous digit with the 
    // carry formed by current
    while(i >= 0) {
        if((i-1) >= 0)
            arr[i-1] = arr[i-1] + arr[i] / 10;
        else {
            arr.insert(arr.begin(), arr[i] / 10);
            // since every digit has been shifted by 1
            arr[1] = arr[1] % 10;
            break;
        }
        arr[i] = arr[i] % 10;
        --i;
    }
   
    // look for the first non-zero digit
    i = 0;
    while(i < arr.size() && arr[i] == 0)
        ++i;
        
    return vector<int>{arr.begin() + i, arr.end()};
}
