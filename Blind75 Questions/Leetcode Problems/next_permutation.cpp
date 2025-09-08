#include <bits/stdc++.h>

using namespace std;


/*
Clear methodology

Given array nums:

Find the pivot (first drop from the right).
Scan i from n-2 down to 0 until nums[i] < nums[i+1].

If no such i exists (array is non-increasing), we’re at the last permutation → reverse whole array and return.

Find the successor to the pivot on the right.
From the end, find the rightmost j > i with nums[j] > nums[i].
(Rightmost ensures the smallest possible increase.)

Swap pivot and successor.

Reverse the suffix i+1 … n-1.
The suffix was in non-increasing order; reversing makes it the smallest order, achieving the next lexicographic permutation.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int first_decreasing = -1;

        // Step 1: Find the first descreasing index from the right where nums[i-1] < nums[i]
        // This identifies the "pivot" where we can make the next permutation larger.
        for(int i = n - 1; i > 0; i--) {
            if(nums[i-1] < nums[i]) {
                first_decreasing = i - 1;
                break;
            }
        }

        // Step 2: If such a pivot exists, find the element just larger than it to the right
        if(first_decreasing >= 0) {
            int next_bigger_index = -1;

            // Find the rightmost element greater than nums[first_decreasing]
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