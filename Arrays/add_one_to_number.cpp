/*  
    Add to number in array form
    https://www.interviewbit.com/problems/add-one-to-number/
*/

// Solution 1

vector<int> Solution::plusOne(vector<int> &num) {
    ++num.back();
    for(int i = num.size()-1; i > 0 && num[i] == 10; i--) {
        num[i] = 0;
        num[i-1] += 1;
    }
    if(num.front() == 10)
        num.front() = 0, num.insert(num.begin(), 1);
    
    // remove zeros in front
    int i = 0;
    while(i < num.size() && num[i] == 0)
        ++i;
    return  vector<int>{num.begin() + i, num.end()};
}

/*
// Solution 2
vector<int> Solution::plusOne(vector<int> &num) {
    int carry = 1;
    // find the first non-zero position from front
    int MSB = 0;
    while(MSB < num.size() && num[MSB] == 0)
        ++MSB;
    for(int i = num.size()-1; i >= MSB; i--) {
        int curr_sum = num[i] + carry;
        num[i] = curr_sum % 10;
        carry = curr_sum / 10;
    }
    // if carry digit is there put it in front
    if(carry != 0) {
        if(MSB == 0)
            num.insert(num.begin(), carry);
        else {
            num[MSB-1] = carry;
            --MSB;
        }
    }
    
    return vector<int>{num.begin() + MSB, num.end()};
}
*/


/* Solution 3
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
*/
