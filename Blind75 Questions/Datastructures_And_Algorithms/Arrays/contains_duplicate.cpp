#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> checker;

        for(auto i=0; i < nums.size(); i++){
            if (checker.insert(nums[i]).second == false) return true; 
            //Attempt to insert and if we fail return false
        }

        return false;
    }
};