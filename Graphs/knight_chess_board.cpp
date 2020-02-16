/* 
    https://www.interviewbit.com/problems/knight-on-chess-board/
    
    Given source and target coordinates, find min number of steps in 
    which a chessboard knight can reach the target.
    If can't reach return -1
*/

// Using BFS
// TC: O(MN)
int Solution::knight(int M, int N, int start_row, int start_col,
                    int end_row, int end_col) {
    queue<pair<int, int>> q;
    q.emplace(make_pair(start_row-1, start_col-1));
    
    // grid to track visited positions
    vector<vector<bool>> grid(M, vector<bool>(N, false));
    // mark it visited
    grid[start_row-1][start_col-1] = true;
    
    // valid knight moves
    vector<pair<int, int>> moves = {   {1, -2}, {-1, -2},
                                    {1, 2}, {-1, 2},
                                    {-2, -1}, {-2, 1},
                                    {2, -1}, {2, 1}
                                };
    
    int level = 0;
    int n_level = q.size();
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        // if the destination is reached
        if(curr.first == end_row-1 && curr.second == end_col-1)
            return level;
            
        // add the different valid possible moves
        for(const auto& move: moves) {
            int r = curr.first + move.first, c = curr.second + move.second;
            // if valid and unvisited
            if(r >= 0 && r < M && c >= 0 && c < N && grid[r][c] == false)
                q.emplace(make_pair(r, c)), grid[r][c] = true;
        }
        --n_level;
        if(n_level == 0) {
            n_level = q.size();
            ++level;
        }
    }
    return -1;
}


///////////////////////////////////////////////////////////////////////////////////////////
// Another way
// TC: O(n.m)
struct Coordinate{
    int x, y;
};

bool doBFS(int n, int m, int r1, int c1, int r2, int c2, int& min_dist){
    // make the chess board as graph
    // we use this for knowing the visited nodes as well as for
    // storing the distances also, initially all are infinite except source
    vector<vector<int>> g(n, vector<int>(m, numeric_limits<int>::max()));

    queue<Coordinate> q;
    // mark source visited
    g[r1-1][c1-1] = 0;
    q.push(Coordinate{r1-1, c1-1});
    Coordinate curr = {};
    // valid steps for a knight
    const vector<Coordinate> steps{{-1, 2}, {1,2}, {2,1}, {2,-1},
                            {1,-2}, {-1,-2}, {-2,-1}, {-2,1}
                        };
    
    while(!q.empty()){
        curr = q.front();
        q.pop();
        
       if(curr.x == r2-1 && curr.y == c2-1){
            min_dist = g[r2-1][c2-1];
            return true;
        }
        // adjacent nodes
        for(auto step: steps){
            if(step.x  + curr.x >= 0 && step.x  + curr.x < n && 
                step.y + curr.y >= 0 && step.y + curr.y < m){
                if(g[step.x + curr.x][step.y + curr.y] == numeric_limits<int>::max()){
                    // mark visited
                    g[step.x + curr.x][step.y + curr.y] = g[curr.x][curr.y] + 1;
                    q.push(Coordinate{step.x + curr.x, step.y + curr.y});
                }            
            }
        }
    }
    return false;
}

int Solution::knight(int n, int m, int r1, int c1, int r2, int c2) {
    int min_dist = 0;
    if(doBFS(n, m, r1, c1, r2, c2, min_dist))
        return min_dist;
    return -1;
}
