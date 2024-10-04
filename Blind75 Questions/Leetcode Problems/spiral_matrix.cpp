/**
 * @file spiral_matrix.cpp
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


class Solution {
public:
    bool inBounds(int maxRows, int MaxCols, int curr_row, int curr_col){
        return (curr_row > 0 && curr_row < maxRows && curr_col > 0 && curr_col < MaxCols);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //Plan
        //Create a copy boolen matrix
        //Create helper functions to go left, right, up, down
        if(matrix.empty()) return {};

        int rowSize = matrix.size();
        int colSize = matrix.at(0).size();
        vector<vector<bool>> visited_matrix (rowSize, vector<bool>(colSize, false));

        vector<int> answer;

        int curr_row = 0;
        int curr_col = 0;

        while (answer.size() < (rowSize*colSize))
        {
            //Explore right
            while(visited_matrix[curr_row][curr_col] == false ){
                answer.push_back(matrix[curr_row][curr_col]);
                visited_matrix[curr_row][curr_col] = true;

                if(inBounds(rowSize, colSize, curr_row, curr_col+1)) curr_col++; //if we can still go left, continue
                else {
                    curr_row--;
                    break;
                }
            }

            //Explore down
            while(visited_matrix[curr_row][curr_col] == false ){
                answer.push_back(matrix[curr_row][curr_col]);
                visited_matrix[curr_row][curr_col] = true;

                if(inBounds(rowSize, colSize, curr_row-1, curr_col))curr_row--; //if we can still go down, continue
                else {
                    curr_col--;
                    break;
                }
            }

            //Explore left
            while(visited_matrix[curr_row][curr_col] == false ){
                answer.push_back(matrix[curr_row][curr_col]);
                visited_matrix[curr_row][curr_col] = true;

                if(inBounds(rowSize, colSize, curr_row, curr_col-1)) curr_col--; //if we can still go left, continue
                else {
                    curr_row++; //go up
                    break;
                }
            }

            //Explore up
            while(visited_matrix[curr_row][curr_col] == false ){
                answer.push_back(matrix[curr_row][curr_col]);
                visited_matrix[curr_row][curr_col] = true;

                if(inBounds(rowSize, colSize, curr_row, curr_row+1)) curr_row++; //if we can still go left, continue
                else {
                    curr_col++; //go right
                    break;
                }
            }

        }

        return answer;


    }
};


class Solution {
public:
    bool inBounds(int maxRows, int maxCols, int curr_row, int curr_col) {
        return (curr_row >= 0 && curr_row < maxRows && curr_col >= 0 && curr_col < maxCols);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<vector<bool>> visited_matrix(rowSize, vector<bool>(colSize, false));
        vector<int> answer;

        int curr_row = 0, curr_col = 0;
        int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
        int totalElements = rowSize * colSize;

        while (answer.size() < totalElements) {
            answer.push_back(matrix[curr_row][curr_col]);
            visited_matrix[curr_row][curr_col] = true;

            int next_row = curr_row;
            int next_col = curr_col;

            if (direction == 0) next_col++;    // move right
            else if (direction == 1) next_row++; // move down
            else if (direction == 2) next_col--; // move left
            else if (direction == 3) next_row--; // move up

            // Check if the next move is valid
            if (inBounds(rowSize, colSize, next_row, next_col) && !visited_matrix[next_row][next_col]) {
                curr_row = next_row;
                curr_col = next_col;
            } else {
                // Change direction
                direction = (direction + 1) % 4;
                if (direction == 0) curr_col++;    // move right
                else if (direction == 1) curr_row++; // move down
                else if (direction == 2) curr_col--; // move left
                else if (direction == 3) curr_row--; // move up
            }
        }

        return answer;
    }
};