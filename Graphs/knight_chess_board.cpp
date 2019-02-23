/* 
    https://www.interviewbit.com/problems/knight-on-chess-board/
    
    Given source and target coordinates, find min number of steps in 
    which a chessboard knight can reach the target.
    If can't reach return -1
*/

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
        
       /if(curr.x == r2-1 && curr.y == c2-1){
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