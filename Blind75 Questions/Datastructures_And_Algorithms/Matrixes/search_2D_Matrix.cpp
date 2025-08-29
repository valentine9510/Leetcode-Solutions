#include <bits/stdc++.h>

using namespace std;

/*

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

/*
⏱️ Time Complexity
Row binary search: O(log m)
Column binary search: O(log n)
Total: O(log m + log n)

📦 Space Complexity
Only a few integers → O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;           // no rows
        int n = matrix[0].size();
        if (n == 0) return false;           // no columns

        // --- Binary Search #1: Find the candidate row ---
        int low = 0, high = m - 1, row = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target > matrix[mid][n - 1]) {
                // target is larger than the last element in this row
                // so it must be in a lower row
                low = mid + 1;
            } else if (target < matrix[mid][0]) {
                // target is smaller than the first element in this row
                // so it must be in a higher row
                high = mid - 1;
            } else {
                // target lies within this row’s range
                row = mid;
                break;
            }
        }

        if (row == -1) return false; // no valid row found

        // --- Binary Search #2: Search inside that row ---
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = matrix[row][mid];

            if (val == target) return true;   // found it
            if (val < target) l = mid + 1;    // go right
            else r = mid - 1;                 // go left
        }

        return false; // not found
    }
};


/* Option 2, treat the array as one long array */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;           // no rows
        int n = matrix[0].size();
        if (n == 0) return false;           // no columns

        // Binary Search over a "virtual" 1D array of length m * n
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Convert mid index into (row, col)
            int r = mid / n;     // row index
            int c = mid % n;     // column index
            int val = matrix[r][c];

            if (val == target) return true;  // found
            if (val < target) low = mid + 1; // search right half
            else high = mid - 1;             // search left half
        }

        return false; // not found
    }
};
