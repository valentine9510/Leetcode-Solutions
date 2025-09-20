#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        std::map<int,int> remainders;

        for(auto i = 0; i<nums.size(); i++){
                if(remainders.find(nums.at(i)) != remainders.end()){
                    //Value in map
                    solution.push_back(i);
                    solution.push_back(remainders[nums.at(i)]);
                    return solution;
                } else {
                    remainders[(target-nums[i])] = i;
                }
        }
        return solution;
            
    }
};
