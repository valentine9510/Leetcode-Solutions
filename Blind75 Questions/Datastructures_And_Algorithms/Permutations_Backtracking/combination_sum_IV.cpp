#include <bits/stdc++.h>

using namespace std;

/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // ---- Top-down helper: count ways to form 'rem' ----
    // memo[rem] caches the number of sequences summing to 'rem'
    long long dfsMemo(int rem, const vector<int>& nums, vector<long long>& memo) {
        if (rem < 0) return 0;            // overshoot ⇒ 0 ways
        if (memo[rem] != -1) return memo[rem];

        long long ways = 0;
        for (int x : nums) {
            if (rem - x >= 0) {
                ways += dfsMemo(rem - x, nums, memo);  // order matters
            }
        }
        return memo[rem] = ways;
    }

    // ---- Bottom-up helper (optional): tabulation ----
    // Order matters ⇒ outer loop on sum, inner on nums
    int tabulate(const vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1; // one way to make 0

        for (int t = 1; t <= target; ++t) {
            long long ways = 0;
            for (int x : nums) {
                if (t - x >= 0) ways += dp[t - x];
            }
            dp[t] = ways;
        }
        return static_cast<int>(dp[target]);
    }

public:
    // ---- Public API: choose your preferred implementation ----
    int combinationSum4(vector<int>& nums, int target) {
        // Top-down (memoized)
        vector<long long> memo(target + 1, -1);
        memo[0] = 1; // base: one way to build 0 (pick nothing)
        long long ans = dfsMemo(target, nums, memo);
        return static_cast<int>(ans);

        // Or, if you prefer bottom-up:
        // return tabulate(nums, target);
    }
};
