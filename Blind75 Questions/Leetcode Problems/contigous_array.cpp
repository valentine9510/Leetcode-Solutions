#include <bits/stdc++.h>

using namespace std;

/*
525. Contiguous Array
Medium
Topics
premium lock icon
Companies
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.

SOLUTION

Core idea (prefix-sum trick)

Turn the problem “equal 0s and 1s” into “prefix sum repeats”:

Treat each 0 as −1 and each 1 as +1.

Let sum[i] be the running sum up to index i.
If the same running sum value appears at two indices i and j (i < j), then the subarray (i+1..j) has net sum 0, meaning it contains equal 0s and 1s (because +1s and −1s cancel).
So if we remember the fIrst index where each running sum value occurred, every time we see that sum again we can form a candidate subarray and update the answer with its length.
Important initialization
Set firstIndex[0] = -1.
This allows a subarray starting at index 0 to be counted when the running sum becomes 0 at some j.

Dry run (short)
nums = [0,1,0,1,1]
Map 0→−1, 1→+1; running sums:

i=0: sum=−1 (first time) store index 0
i=1: sum=0 (seen before at −1) length = 1−(−1)=2
i=2: sum=−1 (seen at 0) length = 2−0=2
i=3: sum=0 (seen at −1) length = 3−(−1)=4 ← best
i=4: sum=1 (first time) store index 4
Answer = 4
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Running sum where 0 counts as -1 and 1 counts as +1.
        int sum = 0;

        // Store the first index at which each running-sum value appears.
        // Key: sum value, Value: first index
        unordered_map<int, int> firstIndex;

        // Critical init: sum==0 is considered seen at index -1,
        // so a subarray starting at 0 can be counted.
        firstIndex[0] = -1;

        int best = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            // Convert 0 -> -1, 1 -> +1 and update running sum.
            sum += (nums[i] == 1 ? 1 : -1);

            // If we've seen this sum before, subarray (firstIndex[sum]+1 .. i)
            // has equal number of 0s and 1s (net sum 0 in that range).
            if (firstIndex.count(sum)) {
                int length = i - firstIndex[sum];
                if (length > best) best = length;
            } else {
                // First time seeing this sum: record index.
                firstIndex[sum] = i;
            }
        }
        return best;
    }
};
