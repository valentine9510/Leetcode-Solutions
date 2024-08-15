/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Number of Islands
 * @version 0.1
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

/**
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
 
 /**
  * @brief Plan
  * 
  * Go through all nodes
  * If I reach an island, increment counter by 1, 
  * 
  * Have a different grid of unexplored islands, initiated to false
  * Set to true for every island that I have explored
  * 
  * 
  * //Base case : root is NULL
  */

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid.at(0).size();

        int numIslands = 0;

        vector<vector<bool>> visitedGrid (rows, (vector<bool>(cols, false)));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && visitedGrid[i][j] == false){
                    //explore
                    explore(grid, visitedGrid, i, j);

                    //add in found islands
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    void explore(vector<vector<char>>& grid, vector<vector<bool>> &visitedGrid, int row, int col){
        // Correct bounds check
        if(col < 0 || col >= grid.at(0).size() || row < 0 || row >= grid.size()) return;

        // If already visited, return
        if(visitedGrid[row][col]) return;
        
        // If not an island, return
        if(grid[row][col] != '1') return; 

        // Mark the current cell as visited
        visitedGrid[row][col] = true;

        // Visit all directions: right, down, left, up
        vector<pair<int, int>> directions {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(auto dir : directions){
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            explore(grid, visitedGrid, newRow, newCol);
        }
    }

};