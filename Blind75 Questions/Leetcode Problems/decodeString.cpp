#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 394. Decode String
Medium
Topics
Companies
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105
 * 
 */

/**
 * @brief Use a stack
 * 
 * add elements until I find a closed bracked, when I find a closed bracket, 
 *  undo the stack until I find the open bracked and multiplier and add it to the stack if it is not empty
 *  if stack is empty, add it to my solution
 * 
 */
class Solution {
public:
    string decodeString(string s) {
        stack<string> storage;
        stack<int> multipliers;
        string result;
        int num = 0;
        
        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');  // Handle multi-digit numbers
            } else if(c == '[') {
                multipliers.push(num);
                num = 0;
                storage.push(result);
                result.clear();
            } else if(c == ']') {
                string temp = result;
                int repeat = multipliers.top();
                multipliers.pop();
                result = storage.top();
                storage.pop();
                
                while(repeat--) {
                    result += temp;
                }
            } else {
                result += c;
            }
        }
        
        return result;
    }
};
