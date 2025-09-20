#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
       if(s.size() != t.size()) return false;
       sort(s.begin(),s.end()); 
       sort(t.begin(),t.end());

       return (s==t);
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> storage; //key and value

        for(int i = 0; i< s.size(); i++){
            storage[s[i]]++;
            storage[t[i]]--;
        }

        //loop through map
        for(auto it = storage.begin(); it != storage.end(); it++)
            if(it->second != 0) return false;

        return true;
    }
};