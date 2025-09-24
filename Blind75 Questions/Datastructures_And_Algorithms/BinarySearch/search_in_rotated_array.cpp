/**
 * @file search_in_rotated_array.cpp
 * @author Valentine Roland
 * @brief search_in_a_rotated array
 * @version 0.1
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>

/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

/*
- Use a modified binary search
- Use 2 pointers, left is the beginning, right is at the end
- Use binary search loop --> while (left <= right) {
- Find midPoint --> int mid = left + (right - left) / 2;

-- Base Cases --> If mid is our target, return mid
-- Find which side is sorted --> If nums[left] <= nums[mid], it means the left half is sorted.
    Update pointers based on left half
        If nums[left] <= target < nums[mid], move the right pointer to mid - 1 (search in the left half).
        Otherwise, move the left pointer to mid + 1 (search in the right half).
-- Else the right side is sorted
    Update pointers based on right half
        If nums[mid] <= target < nums[left], move the left pointer to mid + 1 (search in the right half).
        Else move the right pointer to mid-1 (search in left half)

-- If we escape from this without a value, then it is not int the array

*/

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine if the left side is sorted
            if (nums[left] <= nums[mid]) {
                // Target is in the left side
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {  // Target is in the right side
                    left = mid + 1;
                }
            }
            // Otherwise, the right side is sorted
            else {
                // Target is in the right side
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {  // Target is in the left side
                    right = mid - 1;
                }
            }
        }
        
        return -1;  // Target not found
    }

};













/* Personal solution */
int search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;

    while (low <= high)
    {
        int mid = low + (high-low)/2;

        //Base case 1
        if(nums[mid] == target) return mid;

        //Check which side is sorted
        if(nums[low] <= nums[mid]){ //left is sorted
            if(nums[low] <= target && target < mid) high = mid-1; //go left
            else low = mid+1; //go right 
        } else { //right is sorted
            if(nums[mid] < target && target <= nums[high]) low = mid+1; //go right
            else high = mid-1; //go left 
        }
    }
    
}