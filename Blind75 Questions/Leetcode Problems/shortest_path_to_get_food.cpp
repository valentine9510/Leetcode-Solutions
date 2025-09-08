#include <bits/stdc++.h>

using namespace std;

/*
1730. Shortest Path to Get Food
You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at a food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

Here’s the full interview-style walk-through and a clean C++ solution.

What’s being tested
Graph modeling on grids: mapping a 2D grid to an implicit graph (cells are nodes; 4-neighbor moves are edges).
Shortest path in an unweighted graph: recognizing this is a classic BFS problem.
Edge-case discipline: bounds checking, visited tracking, early exit when food is reached.

Why it shows up in interviews: it checks if you quickly identify BFS as the optimal tool for unweighted shortest paths and implement it cleanly and safely.

Methodology (step-by-step)
Parse the grid to find the start cell '*'.
BFS from the start:
Use a queue of (row, col, distance).
Mark cells as visited as you enqueue (avoid duplicates).
Valid moves: up/down/left/right; skip out-of-bounds and walls 'X'.
First time you pop a '#', return its distance (BFS guarantees shortest).

If BFS exhausts without finding '#', return -1.

Alternatives / Trade-offs
Mutate grid (turn visited cells into 'X') instead of a separate visited array → saves space; slightly less clear if you don’t want to modify input.
Dijkstra / A*: overkill—edges are unit cost, so BFS is optimal.
Bidirectional BFS could be used if there are many foods and a huge grid, but the standard BFS is already linear and simpler.
*/

//Shortest path is always using a queue, BFS
    //Keep a set of visited nodes
    //only add unvisited and valid nodes
    //return the distance



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // LC 1730: Shortest Path to Get Food
    int getFood(vector<vector<char>>& grid) {
        const int R = grid.size();
        if (R == 0) return -1;
        const int C = grid[0].size();
        if (C == 0) return -1;

        // 1) Locate the start '*'
        pair<int,int> start = {-1, -1};
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == '*') {
                    start = {r, c};
                    break;
                }
            }
            if (start.first != -1) break;
        }
        if (start.first == -1) return -1; // no start found (defensive)

        // 2) Standard BFS setup
        queue<tuple<int,int,int>> q; // (row, col, distance)
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        q.emplace(start.first, start.second, 0);
        visited[start.first][start.second] = true;

        // 4-directional moves: up, right, down, left
        static const int dr[4] = {-1, 0, 1, 0};
        static const int dc[4] = {0, 1, 0, -1};

        // 3) BFS loop
        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();

            // If current cell is food, we’re done (BFS guarantees shortest)
            if (grid[r][c] == '#') return d;

            // Explore neighbors
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // Bounds check
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

                // Skip walls and already visited cells
                if (grid[nr][nc] == 'X' || visited[nr][nc]) continue;

                // Valid to visit: open cell 'O', food '#', or even start '*'
                visited[nr][nc] = true;          // mark when enqueuing
                q.emplace(nr, nc, d + 1);        // distance + 1 step
            }
        }

        // 4) No food reachable
        return -1;
    }
};
