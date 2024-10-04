/**
 * @file valid_abbreviation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
The problem "Valid Word Abbreviation" asks you to determine if a string can be validly abbreviated according to certain rules. Given two strings: a word and an abbreviation, the task is to check whether the abbreviation is a valid abbreviation of the word.

Rules for a valid abbreviation:
The abbreviation may contain digits representing how many characters are skipped in the word.
The number cannot have leading zeros.
If there is a number in the abbreviation, it should correspond to skipping that many characters in the word.
Example:
Input:

word = "internationalization"
abbr = "i12iz4n"
Output: true

Explanation:

The abbreviation "i12iz4n" means:
'i' matches the first letter of the word.
'12' skips the next 12 characters, "nternationaliz".
'iz' matches the next two characters of the word.
'4' skips the next 4 characters, "atio".
'n' matches the last character.
Input:

word = "apple"
abbr = "a2e"
Output: false

Approach:
We iterate through both the word and the abbreviation, using two pointers. If the abbreviation contains digits, we skip the corresponding number of characters in the word.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; // Pointer for word
        int j = 0; // Pointer for abbreviation
        
        while (i < word.size() && j < abbr.size()) {
            // If the current character in abbreviation is a digit
            if (isdigit(abbr[j])) {
                // Check for leading zeros, which are not allowed
                if (abbr[j] == '0') return false;
                
                // Read the number in the abbreviation
                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');  // Build the number
                    ++j;
                }
                
                // Skip 'num' characters in the word
                i += num;
            } else {
                // If characters don't match, the abbreviation is invalid
                if (word[i] != abbr[j]) return false;
                
                // Move to the next character in both word and abbreviation
                ++i;
                ++j;
            }
        }
        
        // Check if both pointers reached the end of their respective strings
        return i == word.size() && j == abbr.size();
    }
};

int main() {
    Solution solution;
    
    string word1 = "internationalization";
    string abbr1 = "i12iz4n";
    cout << "Is valid abbreviation: " << (solution.validWordAbbreviation(word1, abbr1) ? "true" : "false") << endl;
    
    string word2 = "apple";
    string abbr2 = "a2e";
    cout << "Is valid abbreviation: " << (solution.validWordAbbreviation(word2, abbr2) ? "true" : "false") << endl;
    
    return 0;
}
