#include <bits/stdc++.h>

using namespace std;

/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/


/* Expanding squares solution */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int max_side = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    int side = 1; // Current square side
                    bool valid = true;

                    while (i + side < rows && j + side < cols && valid) {
                        // Check the new bottom row
                        for (int k = j; k <= j + side; ++k) {
                            if (matrix[i + side][k] != '1') {
                                valid = false;
                                break;
                            }
                        }

                        // Check the new right column
                        for (int k = i; k <= i + side; ++k) {
                            if (matrix[k][j + side] != '1') {
                                valid = false;
                                break;
                            }
                        }

                        if (valid) side++;  // Expand square if still valid
                    }

                    max_side = max(max_side, side);
                }
            }
        }

        return max_side * max_side;  // Return area
    }
};

/*
    Dynamic programming, abit concocted
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_side = 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // Edge row/col — can't look back
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    max_side = max(max_side, dp[i][j]);  // Track largest square
                }
            }
        }

        return max_side * max_side;
    }
};

