#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 
 * 189. Rotate Array
    Medium
    Topics
    Companies
    Hint
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
    Example 2:

    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
    

    Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105
    

    Follow up:

    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?
 * 
 */

/*
nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k > n

        // Reverse helper function
        auto reverse = [&](int start, int end) {
            while (start < end) {
                std::swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };

        // Step 1: Reverse the whole array
        reverse(0, n - 1);
        
        // Step 2: Reverse the first k elements
        reverse(0, k - 1);
        
        // Step 3: Reverse the remaining elements
        reverse(k, n - 1);
    }
};