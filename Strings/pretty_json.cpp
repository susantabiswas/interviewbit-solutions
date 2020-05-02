/*
    Pretty print Json content
    https://www.interviewbit.com/problems/pretty-json/
    TC: O(n)
*/

// Solution 1
vector<string> Solution::prettyJSON(string s) {
    int indent = 0;
    vector<string> result;
    int i = 0;
    
    while(i < s.size()) {
        string line;
        // add the indentation
        for(int j = 0; j < indent; j++)
            line += '\t';
        // if it is a left bracket
        if(s[i] == '{' || s[i] == '[') {
            ++indent;
            line += s[i++];
        }
        // closing bracket
        else if(s[i] == '}' || s[i] == ']') {
            --indent;
            // since this is a closing bracket, 1 indentation
            // needs to be removed
            line.back() = s[i++];
            // if the next char is ',', then it needs to be in same line
            if(i < s.size() && s[i] == ',')
            line += s[i++];
        }
        // other chars, put them on the same line till ',', ], }, {, [
        else {
            while(i < s.size() && s[i] != ',' 
                && s[i] != '[' && s[i] != '{'
                && s[i] != ']' && s[i] != '}') {
                
                line += s[i++];        
            }
            // if the last char is one of the brackets dont put in the 
            // same line, else put it in the same line
            if(s[i] == ',')
                line += s[i++];
        }
        // add the line
        result.emplace_back(line);
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////
// Solution 2
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
