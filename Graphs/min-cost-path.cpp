/*
    https://www.interviewbit.com/problems/min-cost-path/
*/

bool isValid(int r, int c, int &M, int &N) {
    return r >= 0 && r < M && c >= 0 && c < N;    
}

int solution1(int M, int N, vector<string> &grid) {
    // We use a BFS like approach, where instead of a normal
    // queue we use min heap with cost as the key
    struct Position {
        int cost = 0, r, c;
        Position(int cost, int r, int c): cost(cost), r(r), c(c) {};
        bool operator==(const Position& p) const {
            return p.r == r && p.c == c;
        }
    };
    
    struct HashComp {
        size_t operator()(const Position& p) const {
            return hash<int>()(p.cost) ^ hash<int>()(p.r) ^ hash<int>()(p.c); 
        }  
    };
    
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
    unordered_map<char, vector<int>> dir_mapping = {
        {'R', {0,1}},
        {'L', {0,-1}},
        {'U', {-1,0}},
        {'D', {1,0}}
    };
    
    priority_queue<Position, vector<Position>, function<bool(const Position, const Position)> >
        min_heap([](const Position& a, const Position& b)->bool {
            return a.cost >= b.cost;
        });
        
    unordered_set<Position, HashComp> visited;
    // insert the starting position
    min_heap.emplace(Position(0, 0, 0));
    
    while(!min_heap.empty()) {
        auto curr = min_heap.top();
        min_heap.pop();
        
        if(curr.r == M-1 && curr.c == N-1)
            return curr.cost;
        if(!visited.count(curr)) {
            visited.emplace(curr);
            int r = curr.r, c = curr.c;
            for(auto &dir: dirs) {
                if(isValid(dir[0] + r, dir[1] + c, M, N)) {
                    int cost = curr.cost + !(dir_mapping[grid[curr.r][curr.c]] == dir);
                    min_heap.emplace(Position(cost, dir[0] + r, dir[1] + c));
                }
            }
        }
    }
    return 0;
}

int solution2(int M, int N, vector<string> &grid) {
    // We use a 0-1 BFS, where each edge is assumed to have a weight 
    // of either 0 or 1. In this case since following a wrong dir incurs
    // a cost of +1, so we use this.
    // If we incurr a cost for the current edge that is added to the end of queue
    // else if the cost is 0 it is added to front
    struct Position {
        int cost = 0, r, c;
        Position(int cost, int r, int c): cost(cost), r(r), c(c) {};
        bool operator==(const Position& p) const {
            return p.r == r && p.c == c;
        }
    };
    
    struct HashComp {
        size_t operator()(const Position& p) const {
            return hash<int>()(p.cost) ^ hash<int>()(p.r) ^ hash<int>()(p.c); 
        }  
    };
    
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
    unordered_map<char, vector<int>> dir_mapping = {
        {'R', {0,1}},
        {'L', {0,-1}},
        {'U', {-1,0}},
        {'D', {1,0}}
    };
    
    deque<Position> q;
        
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    // insert the starting position
    q.emplace_back(Position(0, 0, 0));
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop_front();
        if(curr.r == M-1 && curr.c == N-1)
            return curr.cost;
            
        if(!visited[curr.r][curr.c]) {
            visited[curr.r][curr.c] = true;
            int r = curr.r, c = curr.c;
            
            for(auto &dir: dirs) {
                if(isValid(dir[0] + r, dir[1] + c, M, N)) {
                    if((dir_mapping[grid[curr.r][curr.c]] == dir)) 
                        q.emplace_front(Position(curr.cost, dir[0] + r, dir[1] + c));
                    else
                        q.emplace_back(Position(curr.cost + 1, dir[0] + r, dir[1] + c));
                }
            }
        }
    }
    return 0;

}

int Solution::solve(int M, int N, vector<string> &grid) {
    // return solution1(M, N, grid);
    return solution2(M, N, grid);
}
