/* 

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0

Note that 1 corresponds to true, and 0 corresponds to false.
 */

//TC: O(n), n: vector size
struct Coordinate{
    int r, c;    
};


int findDFS(vector<string>& grid, Coordinate curr, int pos, string& target){
    if(pos == target.size()-1)
        return 1;
    
    vector<Coordinate> steps = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    // do dfs
    for(auto step: steps){
        Coordinate next;
        next.r = curr.r + step.r;
        next.c = curr.c + step.c;
        
        if(next.r >= 0 && next.r < grid.size() && next.c >= 0 &&
            next.c < grid[curr.r].size() && 
            grid[next.r][next.c] == target[pos + 1]
        ){
            if(findDFS(grid, next, pos + 1, target))
                return 1;
        }
    }
    
    return 0;
}

int Solution::exist(vector<string> &A, string B) {
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[i].size(); j++)
            if(A[i][j] == B[0] && findDFS(A, {i, j}, 0, B))
                return 1;
    return 0;
}

