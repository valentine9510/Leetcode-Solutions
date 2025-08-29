#include <bits/stdc++.h>

using namespace std;


/**
 Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

👉 Final Answer:

Time Complexity: O(n²)
Space Complexity: O(1)

 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array so we can use the two-pointer technique
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Initialize solution with the sum of the first 3 numbers
        // This ensures soln is always valid (no uninitialized variable issue)
        int soln = nums[0] + nums[1] + nums[2];

        // Track the minimum absolute difference we’ve seen so far
        int min_diff = abs(target - soln);

        // Step 3: Loop through each number, treating it as the first element in a triplet
        // We only go until n-2 because we need at least 3 elements
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;       // second pointer (just after i)
            int right = n - 1;      // third pointer (at the end)

            // Step 4: Move the two pointers toward each other
            while (left < right) {
                // Current triplet sum
                int sum = nums[i] + nums[left] + nums[right];

                // Difference between target and current sum
                int diff = target - sum;

                // Step 5: Update solution if this triplet is closer to target
                if (abs(diff) < min_diff) {
                    min_diff = abs(diff);
                    soln = sum;
                }

                // Step 6: Decide which pointer to move
                if (diff == 0) {
                    // Exact match — return immediately
                    return sum;
                } else if (diff > 0) {
                    // sum < target → we need a bigger sum → move left pointer right
                    ++left;
                } else {
                    // sum > target → we need a smaller sum → move right pointer left
                    --right;
                }
            }
        }

        // Step 7: Return the best sum we found
        return soln;
    }
};
