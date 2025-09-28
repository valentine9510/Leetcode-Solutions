#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];                // only one house
        if (n == 2) return max(nums[0], nums[1]);  // circular but trivial

        // Case A: use houses [0 .. n-2] (exclude last)
        int a = robLinear(nums, 0, n - 2);

        // Case B: use houses [1 .. n-1] (exclude first)
        int b = robLinear(nums, 1, n - 1);

        return max(a, b);
    }

private:
    // Standard House Robber (198) on a CLOSED segment [L..R]
    int robLinear(const vector<int>& nums, int L, int R) {
        long take1 = 0; // f(i+1)
        long take2 = 0; // f(i+2)

        // iterate from right to left over [L..R]
        for (int i = R; i >= L; --i) {
            long cur = max<long>(nums[i] + take2, take1);
            take2 = take1;
            take1 = cur;
        }
        return (int)take1;
    }

    // Same recursive shape you had, but add 'R' (right bound)
    int rob_helper(int i, int R, const vector<int>& a,
                   unordered_map<int,int>& memo) {
        if (i > R) return 0;
        if (auto it = memo.find(i); it != memo.end()) return it->second;

        int take = a[i] + rob_helper(i + 2, R, a, memo); // rob i, jump 2
        int skip = rob_helper(i + 1, R, a, memo);        // skip i

        return memo[i] = max(take, skip);
    }

    // Run the linear DP on closed segment [L..R]
    int rob_linear(int L, int R, const vector<int>& a) {
        if (L > R) return 0;
        unordered_map<int,int> memo;     // fresh memo per case
        return rob_helper(L, R, a, memo); // start at L, respect bound R
    }
};
