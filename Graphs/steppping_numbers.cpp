/* Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 

Return the numbers in sorted order.
*/

/* Solution 1: Non graph solution*/
vector<int> Solution::stepnum(int A, int B) {
    vector<int> result;
    int prev = -11;
    int num;
    bool stepping_num = true;
    
    for(int i = A; i <= B; i++){
        stepping_num = true;
        num = i;
        prev = num % 10;
        num /= 10;
        while(num){
            if(abs((num%10) - prev) != 1){
                stepping_num = false;
                break;
            }
            else{
                prev = num % 10;
                num = num / 10;
            }
        }
        
        if(stepping_num)
            result.emplace_back(i);
    }
    
    return result;
}
