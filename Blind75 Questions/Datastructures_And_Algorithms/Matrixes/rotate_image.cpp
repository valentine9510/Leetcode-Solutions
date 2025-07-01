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


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();

        //transpose matrix swap i,j with j,i
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse each row
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
