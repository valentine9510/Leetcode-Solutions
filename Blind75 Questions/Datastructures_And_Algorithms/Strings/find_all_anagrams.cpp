/**
 * @file find_all_anagrams.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
Seen this question in a real interview before?
*/


/*
    Plan

    //Place all characters on p into a map < letter : frequency >

    //For every character in the main string
        //Explore foward and see if it can try to exhaust the map

*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool explore(string &s, string p, unordered_map<char, int> frequency_map, int index){

        for(int i = 0; i < p.size(); i++){
            int new_index = index + i;

            //if out of bounds return false
            if(new_index >= s.size()) return false;

            frequency_map[s[new_index]]--;

            if(frequency_map[s[new_index]] < 0) return false; //we have used more than necessary tries or value does not exist
            if(frequency_map[s[new_index]] == 0) frequency_map.erase(s[new_index]); //remove value as we have used up frequency

        }


        return frequency_map.empty(); //frequency map should be filled in by now
    }

    vector<int> findAnagrams(string s, string p) {
        if(p.empty()) return {};

        vector<int> result;

        //Place all P values onto a frequency map
        unordered_map<char, int> frequency_map;

        for(auto character : p) 
            frequency_map[character]++; //make frequency map

        for(int i = 0; i < s.size(); i++){
            if(frequency_map.find(s[i]) != frequency_map.end()){
                //If value is in frequency map, we can explore
                if (explore(s, p, frequency_map, i) == true ) result.push_back(i);
            }
        }

        return result;
    }
};

/**
 * @brief 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.length() < p.length()) return result;

        vector<int> p_count(26, 0), s_count(26, 0);

        // Build the frequency map for string `p`
        for(char c : p) {
            p_count[c - 'a']++;
        }

        // Initialize the sliding window with the first `p.size()` characters of `s`
        for(int i = 0; i < p.size(); i++) {
            s_count[s[i] - 'a']++;
        }

        // Slide over the string `s`
        for(int i = 0; i <= s.length() - p.length(); i++) {
            // Check if the current window is an anagram of `p`
            if(p_count == s_count) {
                result.push_back(i);
            }

            // Move the window forward
            if(i + p.size() < s.length()) {
                s_count[s[i] - 'a']--; // Remove the character going out of the window
                s_count[s[i + p.size()] - 'a']++; // Add the new character coming into the window
            }
        }

        return result;
    }
};
