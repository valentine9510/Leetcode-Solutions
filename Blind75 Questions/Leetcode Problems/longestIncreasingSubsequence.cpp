#include <bits/stdc++.h>

using namespace std;


/**
 * @brief 
 * 
 * 
 * Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 */

/**
 * @brief Use dp
 * 
 * 
 * start from first element
 *  for any element that we find that is larger
 *      We do dp to find the longest length
 * 
 */
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> sub;

        for (int num : nums) {
            int left = 0, right = sub.size();
            
            // Perform binary search manually
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sub[mid] >= num) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            // If left is at the end, append to sub
            if (left < sub.size()) {
                sub[left] = num;
            } else {
                sub.push_back(num);
            }
        }
        return sub.size();
    }

};