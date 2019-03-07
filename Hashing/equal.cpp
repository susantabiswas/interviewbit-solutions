/*
    Find indices in an array satisfying A[a] + A[b] = A[i] + A[j].
    https://www.interviewbit.com/problems/equal/
    TC: O(n^2)
*/

vector<int> Solution::equal(vector<int> &arr) {
    // stores the final result
    vector<int> final_result;
    // multimap because there can be same sum values
    multimap<int, vector<int>> sum_pair;
    
    // A[a] + A[b] = A[i] + A[j]
    // Each time we check if the sum value is present or not
    // When we are at indices 'a' and 'b', we won't find the sum because 'c'
    // 'd' will appear later and their value will be available later
    // So we can say that i and j are indices 'c' and 'd'
    // Once the sum is found, we just check if the constraints for indices
    // are met or not
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            int curr_sum = arr[i] + arr[j];
            auto res = sum_pair.equal_range(curr_sum);
            
            // if a match has been found
            if(res.first != res.second) {
                for(auto it = res.first; it != res.second; it++) {
                    
                    int a = it->second.front();
                    int b = it->second.back();
                    
                    if(a < i && b != i && b != j) {
                        // current candidate for the answer
                        vector<int> curr_result = {a, b, i, j};
                        if(final_result.empty()) {
                            final_result = move(curr_result);
                        }
                        // check if lexicographically smaller
                        else { 
                            if(curr_result[0] < final_result[0])
                                final_result = move(curr_result);

                            else if(curr_result[1] < final_result[1] &&
                                    curr_result[0] == final_result[0])
                                final_result = move(curr_result);

                            else if(curr_result[2] < final_result[2] &&
                                    curr_result[0] == final_result[0] &&
                                    curr_result[1] == final_result[1])
                                final_result = move(curr_result);
                                
                            else if(curr_result[3] < final_result[3] &&
                                    curr_result[0] == final_result[0] &&
                                    curr_result[1] == final_result[1] &&
                                    curr_result[2] == final_result[2])
                                final_result = move(curr_result);
                        }
                    }
                }
            }
            else
                sum_pair.emplace(curr_sum, vector<int>{i, j});
        }
    }
    
    return final_result;
}
