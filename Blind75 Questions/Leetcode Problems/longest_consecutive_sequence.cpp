#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 128. Longest Consecutive Sequence
Medium

Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4

Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 * 
 */

/**
 * @brief Plan
 * 
 * Sort array, find longest consecutive sequence
 * 
 * use a hash set
 * 
 * 
 * Approach:
Use a Hash Set:
The core idea is to use a set to store all numbers and then check for the start of a sequence by identifying numbers that have no predecessor (i.e., num - 1 doesn't exist).

Time Complexity: O(N) – Each number is processed at most twice.

Space Complexity: O(N) – We use a set to store the numbers.
 * 
 */


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(int num : nums) {
            // Start sequence if num-1 is not found
            if(numSet.find(num - 1) == numSet.end()) { //this is to avoid repeating numbers in a sequence, 
                int currentNum = num;
                int currentStreak = 1;

                // Count consecutive numbers
                while(numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update longest streak
                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
