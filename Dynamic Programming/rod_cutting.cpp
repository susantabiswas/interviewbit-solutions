/*
    Rod cutting order
    https://www.interviewbit.com/problems/rod-cutting/

*/

long long  computeCost(int l, int h, vector<int>& cuts, 
                map<pair<int, int>, long long >& range_cost,
                map<pair<int, int>, int>& range_cut) {
    
    // range doesnt exists
    if(h - l <= 1) {
        return numeric_limits<long long> :: max();;
    }

    if(range_cost.find({l, h}) == range_cost.end()) {
        long long min_cost = numeric_limits<long long> :: max();
        int cut_pos = l + 1;
        // for all the values in the range (l, h) we find the 
        // index which makes the min cut for (l, h)
        for(int i = l + 1; i < h; i++) {
            long long left_cost = 0, right_cost = 0;
            // find the cost for the left and right sides
            left_cost = computeCost(l, i, cuts, range_cost, range_cut);
            right_cost = computeCost(i, h, cuts, range_cost, range_cut);
                
            left_cost = range_cost[{l, i}];
            right_cost = range_cost[{i, h}];
            
            long long  curr_cost = left_cost + right_cost + cuts[h] - cuts[l];
            
            cut_pos = curr_cost < min_cost ? i : cut_pos;
            min_cost = min(min_cost, curr_cost);
        }
        // set the index for cut in (l, h)
        range_cut[make_pair(l, h)] = cut_pos;
        range_cost[make_pair(l, h)] = min_cost;
    }
    
    return range_cost[{l, h}];
}

void addCutPositions(int l, int h, map<pair<int, int>, int>& range_cut,
                    vector<int>& cuts, vector<int>& result) {
    if(h - l <= 1)
        return;
    
    int idx = range_cut[{l, h}];
    
    result.emplace_back(cuts[idx]);
    addCutPositions(l, idx, range_cut, cuts, result);
    addCutPositions(idx, h, range_cut, cuts, result);
}

vector<int> Solution::rodCut(int n, vector<int> &arr) {
    vector<int> cuts;
    cuts.emplace_back(0);
    
    for(const auto& a: arr)
        cuts.emplace_back(a);
        
    cuts.emplace_back(n);
    
    map<pair<int, int>, long long > range_cost;
    map<pair<int, int>, int> range_cut;
    computeCost(0, cuts.size() - 1, cuts, range_cost, range_cut);
    
    vector<int> result;
    // for each range we add the cut position to the result
    addCutPositions(0, cuts.size() - 1, range_cut, cuts, result);
    return result;
}
