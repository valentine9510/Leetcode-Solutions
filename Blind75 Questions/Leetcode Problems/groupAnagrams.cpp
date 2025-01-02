#include <bits/stdc++.h>

using namespace std;

/*
Given an array of strings strs, group the 
anagrams
 together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    bool isAnagram(string left, string right){
        unordered_map<char, int> freq_map;

        for(auto character : left)
            freq_map[character]++;

        for(auto character_right : right){
            freq_map[character_right]--;

            if(freq_map[character_right] < 0)
                return false;
            else if(freq_map[character_right] == 0)
                freq_map.erase(character_right);
        }

        return freq_map.empty(); //map should be empty after
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //for each string

        //check if it is an anagram to the anyelement
        //if it is, add it to the subarray
        //if not, add it as a new entry

        vector<vector<string>> soln;

        for(int i = 0; i < strs.size(); i++){
            vector<string> toAdd = {strs[i]};

            for(int j = 0; j < soln.size(); j++){

                if(isAnagram(strs[i], soln[j][0])){
                    soln[j].push_back(strs[i]); //add to position
                    toAdd.clear();
                }
                    
            }

            if(!toAdd.empty())
                soln.push_back(toAdd);
        }

        return soln;
    }
};

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Hash map to store anagram groups
    unordered_map<string, vector<string>> anagram_map;

    // Iterate through each string
    for (const string& str : strs) {
        // Compute the signature (sorted string)
        string signature = str;
        sort(signature.begin(), signature.end());

        // Add the string to the corresponding group
        anagram_map[signature].push_back(str);
    }

    // Prepare the result
    vector<vector<string>> result;
    for (auto& pair : anagram_map) {
        result.push_back(pair.second);
    }

    return result;
}