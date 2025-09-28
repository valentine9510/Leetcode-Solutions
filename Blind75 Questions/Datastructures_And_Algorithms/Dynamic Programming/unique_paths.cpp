/**
 * @file unique_paths.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>


using namespace std;

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

*/

/*
📌 Summary

Time Complexity: O(m * n) (or O(m * n * (log m + log n)) with string keys).
Space Complexity: O(m * n) for memo + O(m + n) recursion stack.
*/

class Solution {
public:
    unordered_map<string, int> store;
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        if(m == 1 || n == 1) return 1;

        //Memoization by checking for value in the map
        stringstream ss;
        ss << m << ',' << n;
        if(store.find(ss.str()) != store.end()) return store[ss.str()];  

        store[ss.str()] = uniquePaths(m-1, n) + uniquePaths(m , n-1);   
        return store[ss.str()];    
    }

};


/*
Time: O(m · n) states
Space: O(m · n) memo + recursion depth O(m+n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, memo);
    }

private:
    // Count paths from (row, col) to (m-1, n-1)
    int countPaths(int row, int col, int m, int n, vector<vector<int>>& memo) {
        // Out of bounds
        if (row >= m || col >= n) return 0;
        // Reached destination
        if (row == m - 1 && col == n - 1) return 1;

        int& cached = memo[row][col];
        if (cached != -1) return cached;

        // Move down or right
        int down = countPaths(row + 1, col, m, n, memo);
        int right = countPaths(row, col + 1, m, n, memo);

        return cached = down + right;
    }
};
