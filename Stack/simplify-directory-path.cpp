/*
  https://www.interviewbit.com/problems/simplify-directory-path/
*/

// finds the shortest equivalt path for a given input path
string shortestEquivalentPath(const string& dir_path) {
    if(dir_path.empty())
        return "/";
        
    // string stream
    stringstream ss(dir_path);
    string token;
    const char delimiter = '/';

    // for storing the filtered path
    deque<string> path;

    // root case: if the path starts from root then '/' shouldn't be ignored
    if(dir_path.front() == '/')
        path.emplace_back("/");

    while(getline(ss, token, delimiter)) {
        // if token is other than "." and ".." and not empty add
        if(token != "" && token != "." && token != "..") {
            path.emplace_back(token);
        }
        else if(token == "..") {
            // if there is nothing before this or again ".."
            // then just add it
            if(path.empty() || path.back() == "..")
                path.emplace_back(token);
            else {
                // if last token was root "/", then we can't go up to parent
                if(path.back() != "/")
                {  // if there is a parent dir then remove that
                    path.pop_back();
                }
            }
        }
    }

    if(path.empty())
        return "";
        
    // now add "/" between each term, ensuring that if the path starts with
    string shortest_path;
    deque<string>::iterator it = path.begin();
    // add the root term
    shortest_path = *it;
    ++it;    //second term
    // if first term was '/' then we dont add another '/'
    if(shortest_path == "/" && it != path.end()){
        shortest_path += *it;
        ++it;
    }
   
    for(; it != path.end(); it++) {
        shortest_path += "/" + *it;
    }

    return shortest_path;
}
string Solution::simplifyPath(string A) {
    return shortestEquivalentPath(A);
}
