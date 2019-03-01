/*
    https://www.interviewbit.com/problems/count-and-say/
*/

// generates the next sequence based on previous sequence
string generateSequence(string str) {
    string sequence;
    int char_count = 1;
    
    for(int i = 0; i < str.size(); ) {
        char_count = 1;
        while((i + 1) < str.size() && str[i] == str[i+1]) {
            ++char_count;
            ++i;
        }
        sequence += to_string(char_count) + str[i];    
        ++i;
    }
    
    return sequence;
}

string Solution::countAndSay(int n) {
    --n;
    string nth_term = "1";
    
    while(n--) {
        nth_term = generateSequence(nth_term);
    }
    
    return nth_term;
}
