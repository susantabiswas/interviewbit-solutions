/*
  Given n, generate all combinations of well-formed parentheses.
  https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/

void generateAllParenthesis(int n, int left_count, int right_count, int curr, string partial,
                            vector<string>& result, set<string>& s) {
    // if 2*n brackets have been placed
    if(curr == 2 * n) {
        if(s.find(partial) == s.end()) {
            result.emplace_back(partial);
            s.emplace(partial);
        }
        return;
    }
    
    // each time we can either include a left or right bracket
    // insert a left bracket only when no. of left brackets in cmb is less than 'n'
    if(left_count > 0) {
        generateAllParenthesis(n, left_count - 1, right_count, curr + 1, partial + '(',
                                result, s);
    }
    
    // right bracket
    // right bracket can be inserted be there is already a bracket in cmb
    // and the no. of left brackets is more than right brackets
    if(partial.size() > 0 && right_count > left_count) {
        generateAllParenthesis(n, left_count, right_count - 1, curr + 1, partial + ')', 
                            result, s);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    int curr = 0;
    int left_count = n;
    int right_count = n;
    vector<string> result;
    string partial;
    set<string> s;
    
    generateAllParenthesis(n, left_count, right_count, curr, partial, result, s);
    return result;
}
