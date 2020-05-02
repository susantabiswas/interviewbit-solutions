/*
    Reverse words of a sentence
    https://www.interviewbit.com/problems/reverse-the-string/

    TC: O(n)
*/

// Solution 1
string Solution::solve(string s) {
    // create a string removing extra space
    string rev_str;
    
    // add the individual reversed words
    int i = 0, j = 0;
    while(i < s.size()) {
        // skip any space 
        while(s[i] == ' ')
            ++i;
        // add the current word
        string word;
        while(i < s.size() && s[i] != ' ') {
            word += s[i];
            ++i;
        }
        /// reverse the current word
        reverse(word.begin(), word.end());
        // add the word to the sentence, add space to connect words
        rev_str = rev_str + (rev_str.size() == 0 ? word : " " + word);
    }
    // reverse the sentence
    reverse(rev_str.begin(), rev_str.end());
    return rev_str;
}


// Solution 2
void reverseString(string& str, int s, int e) {
    // reverse chars in [s:e] 
    while(s < e) {
        swap(str[s++], str[e--]);
    }
}

/*
    Reverse the words first, then reverse the entire string
*/
void Solution::reverseWords(string &str) {
    if(str.size() <= 1)
        return;
        
    int word_s = 0;
    int word_e = 0;
    
    // find each word and reverse them 
    for(int i = 0; i < str.size(); ) {
        //cout << i<<endl;
        if(str[i] != ' ') {
            // starting index of word
            word_s = i;
            while(i < str.size() && str[i] != ' ')
                ++i;
            // ending index of word
            word_e = i - 1;
            // reverse the word
            reverseString(str, word_s, word_e);
        }  
        else 
            ++i;
    }
    
    // reverse the entire string
    reverseString(str, 0, str.size() - 1);
}
