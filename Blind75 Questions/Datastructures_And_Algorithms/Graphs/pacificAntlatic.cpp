#include <bits/stdc++.h>

using namespace std;

/*

417. Pacific Atlantic Water Flow
Topics
Companies
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

*/

/**
 * Plan
 * 
 * Create 2 oceans
 *  Pacific grid // cells set to true here will be able to reach pacific
 *  Atlantic grid // cells set to true here will be able to reach Atlantic
 * 
 * Start from all cells neighboring ocents and do a DFS to mark cells that can reach from each side!
 * 
 * Do DFS on each of the cells and mark all that can reach
 * 
 * Go through the grid and ensure that which are marked true on both oceans are the result
 * 
 */

 /*
📊 Complexity Analysis

Time Complexity:
Each cell is visited at most twice (once from Pacific, once from Atlantic).
O(m * n)

Space Complexity:
Two m x n visited matrices → O(m * n)
DFS recursion stack → O(m * n) in worst case.
*/
class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Right, Left, Down, Up

    // DFS to mark cells that can reach the ocean
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        ocean[row][col] = true;

        for (auto dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            // Move if within bounds, not visited, and height is non-decreasing
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols 
                && !ocean[new_row][new_col] && heights[new_row][new_col] >= heights[row][col]) {
                dfs(new_row, new_col, heights, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Start DFS from Pacific and Atlantic edges
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific);            // Pacific - Left edge
            dfs(i, cols - 1, heights, atlantic);    // Atlantic - Right edge
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, pacific);            // Pacific - Top edge
            dfs(rows - 1, j, heights, atlantic);    // Atlantic - Bottom edge
        }

        // Find intersection of reachable cells
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};






// for each cell, 
    //use BFS to find if it can reach
        //Antlantic
        //pacific


struct cell {
    int r;
    int c;
};

pair<bool, bool> explorer(vector<vector<int>>& heights, int r, int c) {
    if(heights.empty()) return std::make_pair(false,false);

    bool antlantic;
    bool pacific;

    int r_size = heights.size();
    int c_size = heights[0].size();

    vector<cell> directions = {{1,1}, {1,-1}, {-1,-1}, {-1, 1}};

    //set for visited cells
    vector<vector<bool>> visited (r_size, vector<bool>(c_size, 0));
    queue<cell> q;
    q.push({r,c});

    while (q.empty() == false)
    {
        //Pop top
        cell curr_cell = q.front();
        q.pop();

        //add it to visited
        visited[curr_cell.r][curr_cell.c] = true;

        //check if it touches the edges
        if(curr_cell.r == r_size-1 || curr_cell.c == c_size-1)
            antlantic = true;
        if(curr_cell.r == 0 || curr_cell.c == 0)
            pacific = true;

        //add all directions, if it is lower or equal and if not visited
        for(auto dir : directions){
            cell p_cell = curr_cell;
            p_cell.c += dir.c;
            p_cell.r += dir.r;

            if(p_cell.r < 0 || p_cell.r >= r_size || p_cell.c < 0 || p_cell.c >= c_size)
                continue; //out of bounds
            
            if(!visited[p_cell.r][p_cell.c] && heights[p_cell.r][p_cell.c] <= heights[r][c])
                q.push(p_cell);
        }

    }
    
    return std::make_pair(antlantic, pacific);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
}


/*
📊 Complexity Analysis

Time Complexity:
Each cell is visited at most twice (once from Pacific, once from Atlantic).
O(m * n)

Space Complexity:
Two m x n visited matrices → O(m * n)
DFS recursion stack → O(m * n) in worst case.
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // Matrices to mark reachability from each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Directions for neighbors (up, down, left, right)
        vector<int> dir = {0, 1, 0, -1, 0};

        // DFS function
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& ocean) {
            ocean[r][c] = true; // mark as visited for this ocean

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                // boundary + height condition + not visited yet
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, ocean);
                }
            }
        };

        // Pacific: top row + left column
        for (int c = 0; c < n; c++) dfs(0, c, pacific);
        for (int r = 0; r < m; r++) dfs(r, 0, pacific);

        // Atlantic: bottom row + right column
        for (int c = 0; c < n; c++) dfs(m-1, c, atlantic);
        for (int r = 0; r < m; r++) dfs(r, n-1, atlantic);

        // Collect result where both oceans are reachable
        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
