/*
  Find the number repeated more than n/3 times.
  https://www.interviewbit.com/problems/n3-repeat-number/
*/

/*
  We remove three distinct elements each time during traversal. The two elements remaining elements are then
  checked if they are the ones repeated > n/3 times.
*/
int Solution::repeatedNumber(const vector<int> &arr) {
    unordered_map<int, int> h;
    
    for(int i = 0; i < arr.size(); i++) {
        auto it = h.find(arr[i]);
        // if we have less than two elements 
        if(h.size() < 2 && it == h.end()) {
            h.emplace(arr[i], 1);
        }
        else {
            // not same as one of two
            // then we reduce the counts for the
            // two elements in set by 1 and move the index
            // indicating that three elements have been removed
            if(it == h.end()) {
                for(unordered_map<int, int>::iterator a = h.begin(); a != h.end(); ) {
                    --a->second;
                    if(a->second == 0) {
                        // delete the current element from set
                        auto it = a;
                        ++a;
                        h.erase(it);
                    }
                    else
                        ++a;
                }
            }
            else {  // current is same as one of two already in set
            // increment the frequency count for it
                ++it->second;
            }
        }
    }
    
    if(h.empty())
        return -1;
        
    int repeated = 0;
    int freq = numeric_limits<int> :: min();
    for(auto& a: h) {
        a.second = 0;
    }
     
    for(const auto& a: arr)
        if(h.find(a) != h.end()) {
            ++h[a];
            if(h[a] > freq) {
                freq = h[a];
                repeated = a;
            }
        }
            
    
    return freq > arr.size() / 3 ? repeated : -1;
}
