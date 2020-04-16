/*
  Find the number repeated more than n/3 times.
  https://www.interviewbit.com/problems/n3-repeat-number/
*/

// TC: O(N), SC: O(1)
int Solution::repeatedNumber(const vector<int> &nums) {
    // There are 3 equal parts in the array,
    // if there exists an element that > N/3, that
    // means if 3 unique elements are removed at a time till
    // there are no unique elements, we will have the repeatig element
    // in the end. a a a b b c c 
    // Also there can be only 2 numbers > N/3,
    // so we first need to find the two most frequent elements
    // also if there is a number > N/3, then  
    
    // keeps track of 2 out of 3 elements to remove, 
    // eventually will have the most common elements
    // (element, frequency)
    unordered_map<int, int> frequent_elements;
    
    for(int i = 0 ; i < nums.size(); i++) {
        auto it = frequent_elements.find(nums[i]);
            
        // if we dont have sufficient elements to remove, add the element
        if(frequent_elements.size() < 2 && 
           it == frequent_elements.end()) {
            frequent_elements[nums[i]] = 1;
        }
        else {
            // now that we have 2 elements, 3 elements
            // can only be removed if current element is diff from both of them
            // current element is diff, then remove the 3 elements
            if(it == frequent_elements.end()) {
                // reduce the frequency of tracked elements 
                for(auto el = frequent_elements.begin(); 
                    el != frequent_elements.end(); ) {
                    --(el->second);
                    if(el->second == 0) {
                        // no need to track
                        int number = el->first;
                        ++el;
                        frequent_elements.erase(number);
                    }
                    else 
                        ++el;
                }
            }
            // current elements is same as one of 2, increase the frequency count
            else {
                ++frequent_elements[nums[i]];
            }
        }
    }
    
    // confirm the existence of element with freq > N/3
    int repeating = -1;
    int frequency = 0;
    
    // reset the frequency counts
    auto it = frequent_elements.begin();
    while(it != frequent_elements.end()) {
        it->second = 0;
        ++it;
    }
    
    for(const int& num: nums) {
        if(frequent_elements.count(num)) {
            ++frequent_elements[num];
        
            if(frequent_elements[num] > frequency) {
                frequency = frequent_elements[num];
                repeating = num;
            }
        }
    }
    
    return frequency > (nums.size() / 3) ? repeating : -1;
}


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
