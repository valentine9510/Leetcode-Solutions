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

/*
✅ Complexity

Time: O(n * target)
Space: O(n * target) (memo) + O(n) recursion depth.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Step 1: Find the total sum of all numbers
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: If the sum is odd, it cannot be divided into two equal parts
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;   // The sum we want to build with a subset
        int n = nums.size();

        // Step 3: Create a memo table, initialized to -1 (unknown)
        // memo[index][remaining] = -1 (not calculated), 0 (false), 1 (true)
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        // Step 4: Start recursion from index 0
        return canReachTarget(0, target, nums, memo);
    }

private:
    // Recursive helper function:
    // Can we build "remainingSum" using numbers from position "currentIndex" onward?
    bool canReachTarget(int currentIndex, int remainingSum, const vector<int>& nums, vector<vector<int>>& memo) 
    {
        // Base case 1: success
        if (remainingSum == 0) {
            return true;
        }

        // Base case 2: failure (ran out of numbers or went below 0)
        if (currentIndex >= nums.size() || remainingSum < 0) {
            return false;
        }

        // If already calculated, return stored result
        if (memo[currentIndex][remainingSum] != -1) {
            return memo[currentIndex][remainingSum];
        }

        // Choice 1: include nums[currentIndex] in the subset
        bool takeCurrent = canReachTarget(currentIndex + 1,remainingSum - nums[currentIndex], nums,memo);

        // Choice 2: skip nums[currentIndex]
        bool skipCurrent = canReachTarget(currentIndex + 1,remainingSum,nums, memo);

        // Store result in memo and return
        memo[currentIndex][remainingSum] = (takeCurrent || skipCurrent);
        return memo[currentIndex][remainingSum];
    }
};


/*
A) 1-D DP (knapsack-style)

Idea: Let dp[s] mean “can we make sum s using some of the first i numbers.” Initialize dp[0]=true. For each number x, update sums backwards to avoid reusing the same number.

Steps:

Compute sum. If sum is odd → false.

Target T = sum/2.

Initialize vector<char> dp(T+1, 0); dp[0]=1.

For each x in nums, for s from T down to x: dp[s] |= dp[s-x].

Return dp[T].

This is the standard, clean, and fastest approach for these constraints.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 1. Calculate the total sum
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // 2. If the sum is odd, we cannot split into two equal parts
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2; // we want to see if we can build this sum

        // 3. dp[s] = true means we can make a subset that adds up to s
        vector<bool> dp(target + 1, false);
        dp[0] = true; // we can always make sum 0 (by taking nothing)

        // 4. Process each number
        for (int num : nums) {
            // Traverse backwards so we don’t reuse the same number twice
            for (int s = target; s >= num; s--) {
                if (dp[s - num]) {
                    dp[s] = true; // if we can make (s - num), we can also make s
                }
            }
        }

        // 5. Answer: can we make "target"?
        return dp[target];
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






class Solution {
public:
    bool explorer(vector<int>&nums, vector<bool>& visited,unordered_map<int, bool>& memo, int target){
        if(target < 0) return false;
        if(target == 0) return true;
        if(memo.find(target) != memo.end()) return memo[target];

        for(int i = 0; i < nums.size(); i++){
            //if valid
            if(visited[i]) continue; //Skip visited cells

                //add to visited
                visited[i] = true;
                //try it
                if(explorer(nums, visited,memo,target-nums[i]))
                    return memo[target] = true; // Store result in memo table and return true
                //remove from visited
                visited[i] = false;
        }
        return memo[target] = false; // Store result in memo table and return true
    }
    bool canPartition(vector<int>& nums) {
        vector<bool> visited (nums.size(), false);
        unordered_map<int, bool> memo;
        //find sum
        //find if an index combinations that can sum up to half
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 != 0) return false; //not possible for an odd number to be split

        //check if we have a target that can reach sum/2
        return explorer(nums, visited,memo, sum/2);
    }
};