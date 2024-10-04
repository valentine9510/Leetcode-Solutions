/**
 * @file partition_equal_subset_sum.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
416. Partition Equal Subset Sum
Medium
Topics
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise. 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

/*
    Plan

    Have 2 arrays, left and right

    Base case
    If left_size == right_size return true

    If left_size > right_size return false

    //Try adding numbers to the left and see if they will work

    //Find the sum of all the numbers in nums
    //If not divisible by 2, dont waste your time --> return false
    //canSUM on the half of the total value, are there numbers in the original array that can reach half of that ?


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSubsetSum(vector<int>& nums, unordered_set<int>& visited, int target, unordered_map<int, bool>& memo) { //would be better to use a boolean vector instead of a visit set, just in case the nums array has repeated values!
        if (target == 0) return true;
        if (target < 0) return false;
        
        // Check memoization table
        if (memo.find(target) != memo.end()) return memo[target];
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(i) == visited.end()) {
                // Mark as visited
                visited.insert(i);

                // Try to find solution including nums[i]
                if (canSubsetSum(nums, visited, target - nums[i], memo)) {
                    return memo[target] = true; // Store result in memo table and return true
                }

                // Backtrack: unmark as visited
                visited.erase(i);
            }
        }
        
        return memo[target] = false; // Store result in memo table and return false
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        unordered_set<int> visitSet;
        unordered_map<int, bool> memo;
        return canSubsetSum(nums,visitSet, target, memo);   
    }
};


/**
 * @brief Advanced solution GPT Solution
 * 
 */

class Solution {
public:
    bool subsetSumMemo(vector<int>& nums, int target, int index, vector<vector<int>>& memo) {
        if (target == 0) return true;
        if (index == nums.size() || target < 0) return false;

        if (memo[index][target] != -1) return memo[index][target];

        // Include the current element
        if (subsetSumMemo(nums, target - nums[index], index + 1, memo)) {
            return memo[index][target] = true;
        }

        // Exclude the current element
        if (subsetSumMemo(nums, target, index + 1, memo)) {
            return memo[index][target] = true;
        }

        return memo[index][target] = false;
    }

    bool subsetSum(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return subsetSumMemo(nums, target, 0, memo);
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        return subsetSum(nums, target);   
    }
};