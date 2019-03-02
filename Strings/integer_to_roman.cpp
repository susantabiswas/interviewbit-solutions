/* 
    https://www.interviewbit.com/problems/integer-to-roman/
    TC: O()
*/

/*
    Have all possible values and greedily select the max Roman numeral for
    a value.
*/
string Solution::intToRoman(int num) {
    vector<pair<int, string>> roman_val = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"},  
        {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"},
        {900, "CM"}, {1000, "M"}
    };
    
    string roman;
    
    for(int i = roman_val.size() - 1; i >= 0; i--) {
        if(num <= 0)
            break;
   
        int quo = num / roman_val[i].first;
        while(quo-- > 0) {
            roman += roman_val[i].second;
        }
        num = num % roman_val[i].first;
    }
    
    return roman;
}
