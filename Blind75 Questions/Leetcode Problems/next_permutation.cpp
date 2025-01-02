#include <bits/stdc++.h>


using namespace std;

/*
    A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

    For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
    The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, 
    if all the permutations of the array are sorted in one container according to their lexicographical order, 
    then the next permutation of that array is the permutation that follows it in the sorted container. 
    If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
    Given an array of integers nums, find the next permutation of nums.

    The replacement must be in place and use only constant extra memory.

    Example 1:

    Input: nums = [1,2,3]
    Output: [1,3,2]
    Example 2:

    Input: nums = [3,2,1]
    Output: [1,2,3]
    Example 3:

    Input: nums = [1,1,5]
    Output: [1,5,1]
    

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100
*/

/* 
    Start from end
    the number is greater than the one next to it, swap it

    if we reach the first and we have not swapped

    return the reverse

    Key Concept (Lexicographical Order):
    The next permutation is the next larger permutation that can be formed by rearranging the numbers.

    If the array is already in descending order, the next permutation is the smallest permutation.

    Approach:
    Find the First Decreasing Element (from the right).
    Find the Next Larger Element (just larger than the first decreasing element).
    Swap the two elements.
    Reverse the Right Subarray (to make it the smallest permutation).

    Example: nums = [3,2,1]
    Find the first decreasing element (from the right):
    No decreasing element found.
    Reverse the entire array:
    nums = [1,2,3] (smallest permutation).

    Example: nums = [1,5,8,4,7,6,5,3,1]

    Find the first decreasing element:
    4 < 7 → i = 3.

    Find the next larger element:
    nums[j] = 5 (first element larger than 4).

    Swap 4 and 5.
    nums = [1,5,8,5,7,6,4,3,1].

    Reverse the right part (after 5):
    nums = [1,5,8,5,1,3,4,6,7].

    Complexity Analysis:
    Time Complexity: O(n)
    Finding the first decreasing element: O(n).
    Finding the next larger element: O(n).
    Reversing the subarray: O(n).
    Space Complexity: O(1) (In-place).
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int first_decreasing = -1;

        // Step 1: Find first decreasing element from the right
        for(int i = n - 1; i > 0; i--) {
            if(nums[i-1] < nums[i]) {
                first_decreasing = i - 1;
                break;
            }
        }

        // Step 2: If we found a decreasing element
        if(first_decreasing >= 0) {
            int next_bigger_index = -1;

            // Find the next bigger element to the right of the first decreasing
            for(int i = n - 1; i > first_decreasing; i--) {
                if(nums[i] > nums[first_decreasing]) {
                    next_bigger_index = i;
                    break;
                }
            }

            // Swap them
            std::swap(nums[first_decreasing], nums[next_bigger_index]);
        }

        // Step 3: Reverse the right subarray
        std::reverse(nums.begin() + first_decreasing + 1, nums.end());
    }
};
