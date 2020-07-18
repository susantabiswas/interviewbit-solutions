/*
    https://www.interviewbit.com/problems/woodcutting-made-easy/
    
    TC: O(NlogN)
*/
// Finds the length of wood that will be cut 
long long woodCut(vector<int>& arr, int& height) {
    long long wood_len = 0;
    for(const auto& tree: arr)
        wood_len = wood_len + (tree > height ? tree - height : 0);
    return wood_len;
}

int Solution::solve(vector<int> &arr, int B) {
    int low = 0, high = *max_element(arr.begin(), arr.end());
    
    while(low < high) {
        int height = low + (high - low + 1) / 2;
        long long wood_cut_len = woodCut(arr, height);
        // Since wood length is inversely proportional to height of saw
        // So if we are able to get atleast B lenght wood, we go to the right
        // side to look for higher height
        if(wood_cut_len >= B)
            low = height;
        else
            high = height - 1;
    }
    return low;
}
