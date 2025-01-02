#include <bits/stdc++.h>
using namespace std;

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row){
        unordered_map<char,int> store_map; 

        for(int i = 0; i < board.at(0).size(); i++){
            char temp = board[row][i];
            if(isdigit(temp))
                store_map[temp]++;

            if(store_map[temp] > 1)
                return false;
        }

        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col){
        unordered_map<char,int> store_map; 

        for(int i = 0; i < board.at(0).size(); i++){
            char temp = board[i][col];
            if(isdigit(temp))
                store_map[temp]++;

            if(store_map[temp] > 1)
                return false;
        }

        return true;
    }

    bool isValid3x3(vector<vector<char>>& board, int row, int col){
        unordered_map<char,int> store_map; 

        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                char temp = board[i][j];
                if(isdigit(temp))
                    store_map[temp]++;

                if(store_map[temp] > 1)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> three_by_threes = {{0,0}, {0,3}, {0,6},
                                                   {3,0}, {3,3}, {3,6},
                                                   {6,0}, {6,3}, {6,6}};

        //check 3 by threes
        for(int i = 0; i < three_by_threes.size(); i++){
            if(!isValid3x3(board, three_by_threes[i][0], three_by_threes[i][1]))
                return false;
        }

        //row 
        for(int i = 0; i < board.at(0).size(); i++){
            if(!isValidCol(board, i) || !isValidRow(board, i))
                return false;
        }

        return true;
    }
};