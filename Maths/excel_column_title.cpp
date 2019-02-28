/*
    Convert a number to Excel title
    https://www.interviewbit.com/problems/excel-column-title/
*/

/*
    Each time we divide the number by base i.e 26, the remainder decides the character
    which should be there.
*/
string Solution::convertToTitle(int num) {
    string ans;
    char c;
    const int BASE = 26;
    int place_val = 0;
    
    while(num) {
        place_val = (num % BASE);
        // when the remainder is 0, we can have a bug
        // eg num = 26, then 26/26 = 1, so another time the loop runs
        // because num = 1, but we should have ran the the loop only once
        if(place_val == 0) {
            ans += 'Z';
            num = num /26 - 1;
        }
        else {
            ans += place_val - 1 + 'A';
            num = num / 26;
        }
    }
    
    reverse(ans.begin(), ans.end());
   
    return ans;
}
