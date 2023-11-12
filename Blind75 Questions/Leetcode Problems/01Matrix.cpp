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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> queue;
        int MAX_VALUE = m * n;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.push({i, j});
                } else {
                    mat[i][j] = MAX_VALUE;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.empty()) {
            auto [row, col] = queue.front(); queue.pop();
            for (auto [dr, dc] : directions) {
                int r = row + dr, c = col + dc;
                if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > mat[row][col] + 1) {
                    queue.push({r, c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }
        
        return mat;
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
