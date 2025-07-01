#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * @brief 
     * 
        Initialization:
        First, we determine the size of the matrix:

        m=3m = 3m=3 (rows) and n=3n = 3n=3 (columns).

        MAX_VALUE is set to m×n=9m \times n = 9m×n=9.

        Next, we iterate over the matrix. For every cell that has a 1, we set it to MAX_VALUE (i.e., 9). Every cell with a 0 gets appended to the queue.

        At this point, the matrix looks like:

        +---+---+---+
        | 0 | 0 | 0 |
        +---+---+---+
        | 0 | 9 | 0 |
        +---+---+---+
        | 9 | 9 | 9 |
        +---+---+---+



        And the queue contains: [(0,0), (0,1), (0,2), (1,0), (1,2)].

        BFS Traversal:
        We start the BFS traversal by dequeuing the first element in the queue, which is (0,0).

        We then check its neighboring cells in the directions [(1, 0), (-1, 0), (0, 1), (0, -1)].

        For (0,0), the valid neighbors are (1,0) and (0,1).

        Since (1,0) has a value of 0, we don't need to update its value or enqueue it. Similarly, (0,1) already has a value of 0, so it's not enqueued or updated either.

        The matrix, at this point, looks like:

        +---+---+---+
        | 0 | 0 | 0 |
        +---+---+---+
        | 0 | 9 | 0 |
        +---+---+---+
        | 9 | 9 | 9 |
        +---+---+---+
        

        And the queue is: [(0,1), (0,2), (1,0), (1,2)].

        The process continues, dequeuing (0,1) and checking its neighbors.

        (1,1) will be updated to 1 (from 9) and enqueued.

        This BFS process continues until the queue is empty.

        Final State:
        After processing all the elements in the queue, the matrix is transformed to:

        +---+---+---+
        | 0 | 0 | 0 |
        +---+---+---+
        | 0 | 1 | 0 |
        +---+---+---+
        | 1 | 2 | 1 |
        +---+---+---+

        This matrix represents the shortest distance of each cell to the nearest 0.

        */

        /**
        Step-by-Step Solution
        1. Initialize the Result Matrix:
        Create a result matrix of the same size as the input matrix, mat, and initialize all the cells with a large value (e.g., infinity) except for the cells that are 0 in mat, which should be initialized to 0.

        2. Enqueue All Zeros:
        Use a queue to perform BFS. Enqueue all positions of the cells containing 0 in the matrix.

        3. BFS Traversal:
        Perform BFS from all the 0 cells simultaneously. This will ensure that you find the shortest path to the nearest 0 for each cell. For each cell you process, check its neighbors (up, down, left, right). 
        If the distance to a neighbor can be minimized by going through the current cell, update the distance and add the neighbor to the queue.
        */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Initialize the result matrix with INT_MAX to indicate infinity
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Queue to perform BFS
        queue<pair<int, int>> q;

        // Step 1: Initialize the result matrix and queue with positions of 0's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    // If the cell in mat is 0, set the corresponding result cell to 0
                    result[i][j] = 0;
                    // Add the position of the cell to the queue
                    q.push({i, j});
                }
            }
        }

        // Directions array for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: BFS from all 0's
        while (!q.empty()) {
            // Get the current cell position from the queue
            auto [x, y] = q.front();
            q.pop();

            // Check all four directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx; // New row index
                int ny = y + dy; // New column index

                // Check if the new position is within the bounds of the matrix
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    // If the distance to the neighbor can be minimized
                    if (result[nx][ny] > result[x][y] + 1) {
                        // Update the distance to the neighbor
                        result[nx][ny] = result[x][y] + 1;
                        // Add the neighbor position to the queue
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Return the result matrix with shortest distances
        return result;
    }

    vector<vector<int>> updateMatrixPersonal(vector<vector<int>>& mat) {
        int row_size = mat.size();
        int col_size = mat.at(0).size();

        //Step 1, create a result array filled to infinity
        vector<vector<int>> result (row_size, vector<int> (col_size, INT_MAX));

        //Step 2, Enque all the zeroes in the original array
        queue<pair<int,int>> bfs_queue;

        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < col_size; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    bfs_queue.push(std::make_pair(i,j));
                }
            }
        }

        //Step 3 : BFS, if the values around the cell can be reduced by being close to the current cell, add them to the queue
        vector<vector<int>> directions {{0,1}, {1,0}, {0,-1}, {-1, 0}};

        while (bfs_queue.empty() == false)
        {
            int curr_row = bfs_queue.front().first;
            int curr_col = bfs_queue.front().second;

            bfs_queue.pop(); //remove element from queue

            for(auto direc : directions){
                int new_row = direc.at(0) + curr_row;
                int new_col = direc.at(1) + curr_col;

                //Check bounds
                if(new_col >= 0 && new_col < col_size && new_row >= 0 && new_row < row_size){
                    //if it can be helped, add it to queue
                    if(result[new_row][new_col] > result[curr_row][curr_col] + 1){
                        //Update neighbor value
                        result[new_row][new_col] = result[curr_row][curr_col] + 1;
                        // Add the neighbor position to the queue
                        bfs_queue.push(std::make_pair(new_row, new_col));
                    }
                }
            }
        }
        
        return result;
        
            
    }
};



class Solution1 { //My ineffecient solution
public:
    /**
     * @brief DFS
     * Go through each cell in 2D matrix
     * Use another 2D array to keep track of where we have been
     * When I find a value that is not zero,
     *      Go in all directions and find the closest zero
     * 
     * @param mat 
     * @return vector<vector<int>> 
     */
    int closestZero (vector<vector<int>>& mat, vector<vector<bool>> path, int row, int col, int currentDistance){
        //Ensure we are in bounds
        if(row < 0 || col < 0 || row >= mat.size() || col >= mat.at(row).size()) return INT_MAX; //return in max
        //need to keep track of where we have been
        if(path.at(row).at(col)){
            return INT_MAX; //we have been here
        } else {
            path.at(row).at(col) = true; //update path
        }

        if(mat.at(row).at(col) == 0) return currentDistance; //found it

        currentDistance++; //update distance

        //go left
        int leftDist = closestZero (mat, path, row, col-1, currentDistance);
        if(leftDist == 0) return currentDistance;
        //go right
        int rightDist = closestZero (mat, path, row, col+1, currentDistance);
        if(rightDist == 0) return currentDistance;
        //go up 
        int upDist = closestZero (mat, path, row+1, col, currentDistance);
        if(upDist == 0) return currentDistance;
        //go down
        int downDist = closestZero (mat, path, row-1, col, currentDistance);

        return min(min(leftDist, rightDist), min(downDist, upDist)); 
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int row = 0; row < mat.size(); row++){
            for(int col = 0; col < mat.at(row).size(); col++){
                if(mat.at(row).at(col) != 0){
                    //go in all directions to find zero
                    vector<vector<bool>> paths(mat.size(), vector<bool>(mat.size(), false)); //initialise to false
                    mat.at(row).at(col) = closestZero(mat, paths, row, col, 0);
                }
            }
        }

        return mat;
    }
};


int main(){

    std::cout << "Solution " << endl;

    return 0;
}
