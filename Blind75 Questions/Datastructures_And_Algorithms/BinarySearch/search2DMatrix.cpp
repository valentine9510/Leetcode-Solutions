#include <bits/stdc++.h>

using namespace std;

/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/

/*Flatten the 2D matrix into one array */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target) return true;
            else if (mid_val < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};

/* Binary search on both axes */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // Phase 1: Binary search on first column
        int top = 0, bottom = m - 1, row = -1;

        while (top <= bottom) {
            int mid = (top + bottom) / 2;
            if (target == matrix[mid][0]) return true;
            else if (target < matrix[mid][0]) bottom = mid - 1;
            else top = mid + 1;
        }

        row = bottom; // the last row whose first element is <= target
        if (row < 0) return false;

        // Phase 2: Binary search on that row
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};

