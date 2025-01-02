#include <bits/stdc++.h>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/

/**
 * @brief Dynamic programming
 * 
 * For each index, 
 * 
 *  Do a dynamic programming maximum of all eligible houses
 * 
 *  Base case, index == end of array
 */
class Solution {
public:
    unordered_map<int, int> store; //index to sum 
    int rob_helper(int start_index, vector<int> &n){
        if(store.find(start_index) != store.end()) return store[start_index];

        if(start_index >= n.size()){
            store[start_index] = 0;
            return store[start_index];
        }

        int neighbour_sum = 0;

        for(int i = start_index+2; i < n.size(); i++)
            neighbour_sum = std::max(neighbour_sum, rob_helper(i,n)); //find all possible routes

        store[start_index] = neighbour_sum + n[start_index];
        return store[start_index];

    }

    int rob(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
            ans = std::max(ans,rob_helper(i, nums));
        
        return ans;
    }
};