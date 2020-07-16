/*
  https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
*/

string Solution::solve(string str) {
    queue<char> q;
    unordered_map<char, int> chars_seen;
    string result;
    
    for(char& ch: str) {
        int c = ch - 'a';
        // check if the char was already visited
        // if it was seen remove it from queue
        if(chars_seen[ch] == 0) {
            q.emplace(ch);
        }
        ++chars_seen[ch];
        while(!q.empty() && (chars_seen[q.front()] > 1))
            q.pop();
            
        if(q.empty())
            result.push_back('#');
        else
            result.push_back(q.front());
    }
    return result;
}
