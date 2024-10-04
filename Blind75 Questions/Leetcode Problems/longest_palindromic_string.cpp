/**
 * @file longest_palindromic_string.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    Longest Palindromic Substring
    Solved
    Medium
    Topics
    Companies
    Hint
    Given a string s, return the longest 
    palindromic
    
    substring
    in s.

    

    Example 1:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:

    Input: s = "cbbd"
    Output: "bb"
    

    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

/*
    For each character
	Try to expand outwards
		 If in bounds and is equal 
			® Check if is larger  than our current solution size
                If so update it
    
    //Try for odd numbers and even ones


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) { //For every character, try to expand left and right!
            // Odd-length palindromes
            int start = i;
            int end = i;
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                if ((end - start + 1) > result.size()) { //this condition should be inside the while loop otherwise the while loop cant find the largest value
                    result = s.substr(start, end - start + 1);
                }

                start--;
                end++;
            }

            // Even-length palindromes
            start = i;
            end = i + 1;
            while (start >= 0 && end < s.size() && s[start] == s[end]) {

                if ((end - start + 1) > result.size()) { //this condition should be inside the while loop otherwise the while loop cant find the largest value
                    result = s.substr(start, end - start + 1);
                }

                start--;
                end++;
            }
        }

        return result;
    }
};
