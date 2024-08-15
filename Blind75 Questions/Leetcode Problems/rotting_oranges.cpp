/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Rotting Oranges
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
#include <unordered_set>
#include <math.h>

/**
    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    

    Example 1:


    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
    Example 2:

    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
    Example 3:

    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
    

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange,
    2 representing a rotten orange.
    Every minute, any fresh orange that is adjacent (4 directions: up, down, left, right) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Approach:
    This problem can be solved using Breadth-First Search (BFS). BFS is suitable for this problem because it explores all possibilities level by level (or minute by minute, in this case).

    Steps:
    Identify the initial state: First, we locate all the rotten oranges in the grid and use a queue to process them. These oranges will be our starting points for the BFS.
    BFS Traversal: From each rotten orange, we will rot the adjacent fresh oranges and push them into the queue. We continue this process until no fresh oranges can be rotted (queue is empty).
    Counting the Time: We keep track of the time (in minutes) that has passed during this process.
    Final Check: After the BFS is complete, we check if there are any fresh oranges left. If yes, return -1, indicating that not all oranges could be rotted. Otherwise, return the time taken.

*/
 
using namespace std;


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Helper struct to represent the coordinates and time
struct Cell {
    int x, y, time;
};

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<Cell> q;
    int freshOranges = 0;
    int minutes = 0;

    // Step 1: Initialize the queue with all the initially rotten oranges
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0}); // Rotten orange at (i, j) with time 0
            }
            else if (grid[i][j] == 1) {
                freshOranges++; // Count fresh oranges
            }
        }
    }

    // Step 2: BFS traversal to rot adjacent fresh oranges
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        minutes = current.time;

        for (auto dir : directions) {
            int newX = current.x + dir[0];
            int newY = current.y + dir[1];

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                grid[newX][newY] = 2; // Rot this fresh orange
                q.push({newX, newY, current.time + 1}); // Push into queue with incremented time
                freshOranges--; // Reduce the count of fresh oranges
            }
        }
    }

    // Step 3: Final check if there are any fresh oranges left
    if (freshOranges > 0) {
        return -1; // Impossible to rot all oranges
    }

    return minutes; // Return the time taken to rot all oranges
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);
    if (result == -1) {
        cout << "All oranges cannot be rotted.\n";
    } else {
        cout << "Minimum time to rot all oranges: " << result << " minutes.\n";
    }

    return 0;
}


 /**
  * @brief Plan
  * 
  * Easy loop through many times until there are no oranges left
  * 
  * //Loop through and only add rotten oranges to the queue, BFS
  *     //Start popping from queue
  *     //whenever a neighbor is a health oragne and is affected, add it to queue
  *     //tun until the queue is empty
  * 
  * 
  * //put all rotten organges to a map
  * //put all healthy oranges to a map
  * 
  * //always loop through the rotten oranges map, count the number of loops you neeed to remove all the healthy oranges
  */
class PersonalSolution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num_healthy_oranges = 0;
        vector<string> bad_oranges;

        int maxRow = grid.size();
        int maxCol = grid.at(0).size();

        for(int i = 0; i< maxRow; i++){
            for(int j=0; j<maxCol; j++){
                if(grid[i][j] == 1){
                    num_healthy_oranges++;
                }

                if(grid[i][j] == 2){
                    //Add to rotten store 
                    stringstream input;
                    input << i << " " << j;
                    bad_oranges.push_back(input.str());  
                }
            }
        }

        int minuteCounter = 0;

        while (num_healthy_oranges > 0)
        {
            int initialHealthyOranges = num_healthy_oranges;

            //scroll through all the bad oranges and infect anyone right next to them
                //remove any healthy orange as I do that
            int initialSize = bad_oranges.size();
            for(int i =0; i < initialSize; i++){
                stringstream output;
                int row, col;
                
                output >> row >> col; //extract row and col


                vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

                for(auto dir : directions){
                    int newRow = row + dir.at(0);
                    int newCol = col + dir.at(1);

                    stringstream newPotentialRottenOrange;
                    newPotentialRottenOrange << newRow << " " << newCol;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                        num_healthy_oranges--; //reduce on healthy oranges
                        grid[newRow][newCol] = 2; //rot orange

                        //add it to the bad oranges too
                        bad_oranges.push_back(newPotentialRottenOrange.str());
                    }
                }
            }

            if(num_healthy_oranges == initialHealthyOranges) return -1; //we could not affect any orange, so return
            

            //increment minuteCounter
            minuteCounter++;
        }

        return minuteCounter;
        
    }

};