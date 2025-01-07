#include <bits/stdc++.h>

using namespace std;

/**
 * 287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.


Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
 * 
 */

/**
 Use Floyds, cycle detection

 Code (Corrected with Floyd’s Cycle Detection):


 How This Works:
Cycle Detection (Phase 1):

Treat the array as a linked list where nums[i] points to the next node.
Use two pointers (slow and fast), moving slow by one step and fast by two steps to detect a cycle.
If there is a cycle, the two pointers will eventually meet.
Finding Duplicate (Phase 2):

After the cycle is detected, reset one pointer (slow) to the start of the array and move both pointers one step at a time.
The point where they meet again is the start of the cycle, which corresponds to the duplicate number.
 * 
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Phase 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Find the entrance of the cycle (duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        ///treat numbers as indices
        //find cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        //cycle is found, now find the beginning of the cycle
        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow; //they meet at beginning of cycle
    }
};