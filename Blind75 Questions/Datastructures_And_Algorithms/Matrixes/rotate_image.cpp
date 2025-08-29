#include <bits/stdc++.h>

using namespace std;

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/

/*
STRATEGY

🎯 Strategy:
Transpose the matrix (flip across the diagonal)

Reverse each row

🔄 Step-by-Step Breakdown
Step 1: Transpose
Swap matrix[i][j] with matrix[j][i].

1 2 3        1 4 7
4 5 6   →    2 5 8
7 8 9        3 6 9
Step 2: Reverse each row

1 4 7   →   7 4 1
2 5 8   →   8 5 2
3 6 9   →   9 6 3
✅ Done!


*/

/*
    Complexity

    Time: O(N^2) (we touch each element a constant number of times).

    Space: O(1) extra space (in place).
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n <= 1) return; // 0x0 or 1x1 are already “rotated”

        // 1) Transpose: swap (i,j) with (j,i) for j > i
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2) Reverse each row (horizontal flip)
        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        /* Transponse the matrix by swapping i,j with j,i for j > i */
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix.size(); j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }


        /* Reverse each row */
        /* Transponse the matrix by swapping i,j with j,i*/
        for(int i = 0; i < matrix.size(); i++){
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};