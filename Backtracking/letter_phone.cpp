/*
    For a given number, find all possible keypad combinations
    https://www.interviewbit.com/problems/letter-phone/
*/

void findNumberCombinations(string num, int curr, string partial, 
                    vector<string>& result, unordered_map<char, string>& mappings) {
    
    // if all the digits have been covered
    if(curr == num.size()) {
        result.emplace_back(partial);
        return;
    }
    
    // for current digit try all its mappings
    string curr_mapping = mappings[num[curr]];
    for(int i = 0; i < curr_mapping.size(); i++) {
        findNumberCombinations(num, curr + 1, partial + curr_mapping[i],
                    result, mappings);
    }
}

vector<string> Solution::letterCombinations(string num) {
    unordered_map<char, string> mappings = {
        {'0', "0"},
        {'1', "1"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    vector<string> result;
    string partial;
    int curr = 0;
    
    findNumberCombinations(num, curr, partial, result, mappings);
    return result;
}
