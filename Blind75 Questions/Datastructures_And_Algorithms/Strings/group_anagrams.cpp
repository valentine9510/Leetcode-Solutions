#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string left, string right){
        if(left.size() != right.size()) return false;

        map<char, int> store;

        for(int i = 0; i < right.size(); i++){
            store[right[i]]++;
            store[left[i]]--;
        }

        for(auto temp : store)
            if(temp.second != 0) return false;

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> soln;

        for(auto curr_string : strs){
            bool added = false;

            /* Try to add to current soln if any */
            for(int i = 0; i < soln.size(); i++){ 
                if(isAnagram(curr_string, soln[i][0])){
                    soln[i].push_back(curr_string);
                    added = true;
                }
            }

            /* Add to soln if not added */
            if(!added){
                vector<string> temp {curr_string};
                soln.push_back(temp);
            }
        }

        return soln;
    }
};