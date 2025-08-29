#include <bits/stdc++.h>

using namespace std;

/* 
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
*/

#include <vector>
#include <random>
#include <numeric>   // std::partial_sum
#include <algorithm> // std::upper_bound

class Solution {
    std::vector<long long> pref; // prefix sums (use 64-bit to be safe)
    long long total = 0;

    // Good RNG for production code
    std::mt19937_64 rng;
    std::uniform_int_distribution<long long> dist; // [1, total]

public:
    Solution(std::vector<int>& w) {
        // Build prefix sums: pref[i] = w[0] + ... + w[i]
        pref.resize(w.size());
        std::partial_sum(w.begin(), w.end(), pref.begin(),
                         [](long long a, int b){ return a + b; });
        total = pref.back();

        // Seed RNG once
        std::random_device rd;
        rng = std::mt19937_64(rd());

        // Initialize distribution over [1, total]
        dist = std::uniform_int_distribution<long long>(1, total);
    }
    
    int pickIndex() {
        // Draw a target in [1, total]
        long long target = dist(rng);

        // Find first prefix >= target
        auto it = std::upper_bound(pref.begin(), pref.end(), target - 1);
        return static_cast<int>(it - pref.begin());
    }
};
