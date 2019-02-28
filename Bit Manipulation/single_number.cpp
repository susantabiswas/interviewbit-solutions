/*
    Since every element appears twice except for one, doing XOR should cancel every pair
*/
int Solution::singleNumber(const vector<int> &arr) {
    int num = 0;
    for(const auto& a: arr)
        num ^= a;
        
    return num;
}
