/**
 * @file wordbreak.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**

139. Word Break
Medium
Topics
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

 */

/**
 * @brief Dynamic Programming
 * 
 * Plan
 * 
 * Go a word in the word dictionary
 * 
 * Keep removing the prefixes
 * If we can remove the prefix, recurse, 
 * 
 * If none of the words can be a prefix, return false
 * 
 */

#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    unordered_map<string, bool > store;

    bool wordBreakUnoptimized(string s, vector<string>& wordDict) {
        if(s.empty()) return true;

        for(auto word : wordDict){
            if(s.find(word) == 0){
                //word is a prefix
                string updateInput {s};
                updateInput.erase(0,word.size());

                if(wordBreak(updateInput,wordDict)) return true; //if we can finish it return true
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(store.find(s) != store.end()) return store[s];
        if(s.empty()) return true;

        for(auto word : wordDict){
            if(s.find(word) == 0){
                //word is a prefix
                string updateInput {s};
                updateInput.erase(0,word.size());

                if(wordBreak(updateInput,wordDict)){
                    store[updateInput] = true;
                    return true; //if we can finish it return true
                } 
            }
        }

        store[s] = false;
        return false;
    }
};