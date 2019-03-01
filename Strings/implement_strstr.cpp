// for computing LPS values of pattern
vector<int> computeLPS(string patt) {
    int i = 1, j = 0;
    vector<int> lps(patt.size(), 0);
    
    while(i < patt.size()) {
        if(patt[i] == patt[j]) {
            lps[i]  = j + 1;
            ++i, ++j;
        }
        else {
            if(j != 0) {
                j = lps[j - 1];
            }
            else 
                ++i;
        }
    }
    
    return lps;
}

// for doing KMP string matching
int KMP(const string str, const string patt) {
    if(patt.size() > str.size())
        return -1;
    if(str.size() < 1 || patt.size() < 1)
        return 0;
        
    // compute the LPS values for pattern
    vector<int> lps = computeLPS(patt);
   
    int i = 0, j = 0;
    while(i < str.size()) {
           
        if(patt[j] == str[i]) {
            ++i, ++j;
            if(j == patt.size()) {
                return i - patt.size();
            } 
        }
        else {
            if(j != 0) 
                j = lps[j - 1];
            else if(j == 0)
                ++i;
        }
    }
    
    return -1;
}

// for doing string matching using Rabin Karp
int RabinKarp(const string str, const string patt) {
   if(patt.size() > str.size())
        return -1;
    if(str.size() < 1 || patt.size() < 1)
        return 0;
        
    int patt_hash = 0, str_hash = 0;
    int patt_power = 1;
    const int base = 26;
    const int N = str.size();
    const int M = patt.size();
    
    // compute the hash value for pattern and 1st window of string
    for(int i = 0; i < M; i++) {
        patt_power = i ? patt_power * base : 1;
        patt_hash = patt_hash * base + patt[i]; 
        str_hash = str_hash * base + str[i];
    }

    
    for(int i = 0; i <= N - M; i++) {
        // both the string window and pattern have the hash values, check if they
        // are same 
        if(str_hash == patt_hash && !str.compare(i, M, patt))
            return i;
        // remove first char of current window, and add first char of next window
        str_hash = str_hash - (patt_power * str[i])  ;
        str_hash = str_hash * base + str[i + M];
        
    }
    
    return -1;    
}

int Solution::strStr(const string str, const string patt) {
    return KMP(str, patt);
    //return RabinKarp(str, patt);
}
