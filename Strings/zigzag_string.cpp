/*
    Zigzag string
    https://www.interviewbit.com/problems/zigzag-string/
*/

string Solution::convert(string str, int n) {
    if(n <= 1)
        return str;
        
    vector<string> v(n, "");
    int c = 0;
    bool down = true;
    for(int i = 0; i < str.size(); i++) {
        //cout << c<<endl;
        v[c] += str[i];
            
        if(c == n - 1) {
            down = false;
            --c;
        }
        else if(c == 0 && down == false) {
            down = true;
            ++c;
        }
        else if(down) {
            ++c;
        }
        else if(down == false)
            --c;
        
    }
    
    string result;
    for(auto& a: v)
       result += a;
        
    return result;
}
