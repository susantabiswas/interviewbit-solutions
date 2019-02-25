/*
    Ditinct numbers in window of size k
    https://www.interviewbit.com/problems/distinct-numbers-in-window/  
    TC: O (n)
    SC: O(k)
*/
vector<int> Solution::dNums(vector<int> &arr, int k) {
    unordered_map<int, int> h;
    vector<int> result;
    
    // first window 
    for(int i = 0; i < k; i++) {
        if(h.find(arr[i]) == h.end())
            h.emplace(arr[i], 1);
        else
            ++h[arr[i]];
    }
    
    for(int i = 0; i <= arr.size() - k; i++) {
        result.emplace_back(h.size());
        
        // move to next window
        auto it = h.find(arr[i]);
        // remove the first element of current window
        if(it != h.end()) {
            --(it->second);
            if(it->second == 0)
                h.erase(it);
          //  cout <<"i:"<<i<<endl;
        }
        if((i + k) < arr.size()) {
            // add the first element of next window
            if(h.find(arr[i + k]) == h.end())
                h.emplace(arr[i + k], 1);
            else
                ++h[arr[i + k]];
        }
    }
    return result;
}
