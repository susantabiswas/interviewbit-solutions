/*
    Pretty print Json content
    https://www.interviewbit.com/problems/pretty-json/
    TC: O(n)
*/

string writePrettyLine(char c, int tab_c) {//cout<<"tab:"<<tab_c<<endl;
    string result;
    // add indentation tabs
    while(tab_c-- > 0) {
        result += "\t";
    }
    // write the char
    result += c;
    return result;
}

vector<string> Solution::prettyJSON(string json) {
    int tab_c = 0;
    vector<string> result;
    
    
    for(const auto& c: json) {
        // opening brace, increase number of tab count, put the brace in new line after that many tabs 
        if(c == '{' || c == '[') {
            string line = writePrettyLine(c, tab_c);
            ++tab_c;
            result.emplace_back(line);
        }
        // closing brace, decrement tab count, put the brace in new line after that many tabs
        else if(c == '}' || c == ']') {
            --tab_c;
            string line = writePrettyLine(c, tab_c);
            result.emplace_back(line);
        }
        else if(c == ',') { // append to last line
            result.back() += c;
        }
        else { // normal chars
    
            char last_char =  result.back().back();      
            if(last_char == ']' || last_char == '}' || last_char == '[' ||
                last_char == '{' || last_char == ',' ) {
                string line = writePrettyLine(c, tab_c);
                result.emplace_back(line);
            }
            else {
                result.back() += c;
            }
        }
    }
   
    return result;
}
