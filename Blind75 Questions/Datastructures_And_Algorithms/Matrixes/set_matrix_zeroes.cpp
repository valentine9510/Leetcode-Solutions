#include <bits/stdc++.h>

using namespace std;

/*
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

    You must do it in place.

 
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            Find all rows and find all columns, then set them to zero
        */

        vector<int> rows;
        vector<int> cols;

        for(int i =0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.at(i).size(); j++){
                if(matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        //remove duplicates
        sort(rows.begin(), rows.end());
        auto newEnd = std::unique(rows.begin(), rows.end());
        rows.erase(newEnd, rows.end());

        //remove duplicates
        sort(cols.begin(), cols.end());
        auto newEnd2 = std::unique(cols.begin(), cols.end());
        cols.erase(newEnd2, cols.end());

        //Clear all rows
        for(int i = 0; i < rows.size(); i++){
            for(int j = 0; j < matrix.at(rows[i]).size(); j++){
                matrix[rows[i]][j] = 0;
            }
        }

        //Clear all columns
        for(int i = 0; i < cols.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                matrix[j][cols[i]]= 0;
            }
        }
    }
};