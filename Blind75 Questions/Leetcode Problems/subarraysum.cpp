#include <bits/stdc++.h>

using namespace std;

/*
560. Subarray Sum Equals K
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/


int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for (int start = 0; start < nums.size(); start++) {
        int sum = 0;
        for (int end = start; end < nums.size(); end++) {
            sum += nums[end];
            if (sum == k)
                count++;
        }
    }
    return count;
}


/* Using a prefix map */
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // Base case: prefix sum of 0 exists once

    int currSum = 0, count = 0;

    for (int num : nums) {
        currSum += num;

        // Check if there is a prefix sum such that currSum - prefix = k
        if (prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currSum - k];
        }

        // Add/update the current prefix sum in the map
        prefixSumCount[currSum]++;
    }

    return count;
}
