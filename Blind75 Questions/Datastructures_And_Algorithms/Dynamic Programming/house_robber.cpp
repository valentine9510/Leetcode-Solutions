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

/*
    DFS with memoization


*/


class Solution {
public:
    int rob_helper(int start_index, vector<int> &n, unordered_map<int,int> &map){
        if(start_index >= n.size()) return 0;
        if(map.find(start_index) != map.end()) return map[start_index];

        int sum = 0;

        // Option 1: Rob current house i, then move to i+2
        int robCurr = n[start_index] + rob_helper(start_index + 2, n, map);

        // Option 2: Skip current house i, move to i+1
        int robNext = rob_helper(start_index + 1, n, map);

        sum = std::max(robCurr, robNext);
        map[start_index] = sum;

        return sum;
    }

    int rob(vector<int>& nums) {
        unordered_map<int,int> store;

        return rob_helper(0,nums,store);
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        long next1 = 0; // f(i+1)
        long next2 = 0; // f(i+2)

        // Walk from rightmost to leftmost
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            long take = nums[i] + next2; // rob current, jump two
            long skip = next1;           // skip current, use f(i+1)
            long cur  = max(take, skip);

            // Roll the window forward
            next2 = next1;
            next1 = cur;
        }
        return (int)next1; // f(0)
    }
};
