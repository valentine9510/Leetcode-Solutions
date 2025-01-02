#include <bits/stdc++.h>

using namespace std;

/*
287. Find the Duplicate Number
Medium
Topics
Companies
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
 
*/

/**
 * @brief Plan
 * 
    Approach 1: Floyd’s Tortoise and Hare (Cycle Detection)
    This problem can be visualized as finding a cycle in a linked list, where the array indices represent pointers to the next element.
 
    Algorithm (Step-by-Step):
    Phase 1: Detect Intersection (Cycle)

    Since there is a cycle, the fast pointer will always find the next index quick

    Use two pointers (slow and fast).
    slow moves one step at a time.
    fast moves two steps at a time.
    If slow and fast meet, a cycle exists.
    Phase 2: Find the Start of the Cycle (Duplicate Number)

    Reset slow to the start (nums[0]) and keep fast at the intersection point.
    Move both slow and fast one step at a time.
    The point where they meet is the duplicate number.

 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle (intersection point)
        do {
            slow = nums[slow];          // Move slow by 1 step
            fast = nums[nums[fast]];    // Move fast by 2 steps
        } while (slow != fast);

        // Phase 2: Find entry point of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];  // Move slow by 1 step
            fast = nums[fast];  // Move fast by 1 step
        }
        
        return slow;  // This is the duplicate number
    }

};


int findDuplicate(vector<int>& nums) {
    int fast = nums[0];
    int slow = nums[0];

    //look for the cycle
    do {
        slow = nums[slow]; //move by 1
        fast = nums[nums[fast]]; //move by 2
    } while (fast != slow);

    //Find entry of cycle
    /*
        The distance from the start of the list to the start of the cycle is equal to the distance from the meeting point inside the cycle to the start of the cycle.
    */
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow; //this is the duplicate    
}