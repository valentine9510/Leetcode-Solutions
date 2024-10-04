/**
 * @file word_search.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
    Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
    Example 2:

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true
    Example 3:

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false

    Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
    

    Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>

using namespace std;

/*
    Plan

    Go through matrix
        If we find a letter that the word begins with
            Start to explore
                Use a visit grid or set to know where you have been

            Explore function
                If string is empty --> return true

                Check if you are in bounds 
                If you have visited cell --> return false
                If current_cell is not the first letter of the string --> return false

                mark cell as visited
                //Recursively check left, right, up, down
                    If any of them return true --> return true
                //If none return true --> return false



 */

class Solution {
public:
    bool explore(vector<vector<char>>& board, vector<vector<bool>>& visit_grid, int row, int col, string word){
        // Explore function
        //If string is empty --> return true
        if(word.empty()) return true;

        //Check if you are in bounds
        int maxRows = board.size();
        int maxCols = board.at(0).size();
        if(row < 0 || row >= maxRows || col < 0 || col >= maxCols) return false;

        //If you have visited cell --> return false
        if(visit_grid[row][col]) return false;

        //If current_cell is not the first letter of the string --> return false
        if(word.at(0) != board[row][col]) return false;

        //mark cell as visited
        visit_grid[row][col] = true;

        //Update word by removing the prefix
        string new_word {word};
        new_word.erase(0,1);

        vector<pair<int,int>> directions {{0,1}, {0,-1}, {1,0}, {-1, 0}};

        //Recursively check left, right, up, down
        //If any of them return true --> return true
        //If none return true --> return false
        for(auto dir : directions){
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if(explore(board, visit_grid, newRow, newCol, new_word)) return true;
        }

        //mark cell as unvisited
        visit_grid[row][col] = false;

        return false;        
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(word.empty()) return true;

        int maxRows = board.size();
        int maxCols = board.at(0).size();

        //Visit all cells
        for(int row = 0; row < maxRows; row++){
            for(int col = 0; col < maxCols; col++){
                if(word.at(0) == board[row][col]){
                    //We have found the beginning of the word so explore

                    //Create visited grid
                    vector<vector<bool>> visit_grid (maxRows, (vector<bool>(maxCols, false)));

                    if(/*explore function*/explore(board, visit_grid, row, col, word) == true) return true;
                }
            }
        }

        return false;
    }
};


class Solution {
public:
    bool explore(vector<vector<char>>& board, vector<vector<bool>>& visit_grid, int row, int col, const string &word, int index){
        // If index equals word length, all characters are matched
        if(index == word.size()) return true;

        // Check if out of bounds
        int maxRows = board.size();
        int maxCols = board[0].size();
        if(row < 0 || row >= maxRows || col < 0 || col >= maxCols) return false;

        // Check if the cell is already visited or the character does not match
        if(visit_grid[row][col] || board[row][col] != word[index]) return false;

        // Mark the cell as visited
        visit_grid[row][col] = true;

        // Explore all 4 possible directions
        vector<pair<int,int>> directions {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        for(auto dir : directions){
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if(explore(board, visit_grid, newRow, newCol, word, index + 1)) return true;
        }

        // Backtrack: unmark the cell
        visit_grid[row][col] = false;

        return false;        
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;

        int maxRows = board.size();
        int maxCols = board[0].size();

        // Visit all cells
        for(int row = 0; row < maxRows; row++){
            for(int col = 0; col < maxCols; col++){
                if(board[row][col] == word[0]){
                    // Create visited grid
                    vector<vector<bool>> visit_grid(maxRows, vector<bool>(maxCols, false));

                    // Start exploring from the current cell
                    if(explore(board, visit_grid, row, col, word, 0)) return true;
                }
            }
        }

        return false;
    }
};
