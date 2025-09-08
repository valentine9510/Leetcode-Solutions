/**
 * @file letter_combinations_of_a_phone_number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    17. Letter Combinations of a Phone Number
    Medium
    Topics
    Companies
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


    

    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Example 2:

    Input: digits = ""
    Output: []
    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]
    

    Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/
#include <bits/stdc++.h>
using namespace std;

/*
    Plan
    If current_solution_size == digits size
        Add it to final solution

    For each letter at an index
        Add it to current solution
            Create combinations from other digits in the string
        Remove it from current solution

    Return final
*/

class Solution {
private:
    const unordered_map<char, string> keyboard {
      {'2',"abc"}, 
      {'3',"def"},  
      {'4',"ghi"},  
      {'5',"jkl"},  
      {'6',"mno"},  
      {'7',"pqrs"},  
      {'8',"tuv"}, 
      {'9',"wxyz"},  
    };

public:
    void letterComboHelper(string &digits, vector<string> &result, int start_index, string current_combo){
        if(current_combo.size() == digits.size()){
            result.push_back(current_combo);
            return;
        }

        // Process the current digit
        string digit_letters = keyboard.at(digits[start_index]);

        for(int j = 0; j < digit_letters.size(); j++){
            // Add a letter to the current combination
            current_combo.push_back(digit_letters[j]);

            // Recurse to create combinations from the next digit
            letterComboHelper(digits, result, start_index + 1, current_combo);

            // Remove the letter after backtracking
            current_combo.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits.empty()) return result;  // Handle edge case for empty input

        letterComboHelper(digits, result, 0, "");

        return result;
    }
};