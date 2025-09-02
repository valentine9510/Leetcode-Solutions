#include <bits/stdc++.h>

using namespace std;

/*
424. Longest Repeating Character Replacement
Solved
Medium
Topics
premium lock icon
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 
*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxWindow = 0;
        int mostFreq = 0; // BUG 1: must initialize

        for (int right = 0; right < (int)s.size(); ++right) {
            int r = s[right] - 'A';
            freq[r]++;
            mostFreq = max(mostFreq, freq[r]); // track best freq in window

            // Keep window valid: (windowLen - mostFreq) <= k
            // BUG 3: use while to maintain invariant robustly
            while ((right - left + 1) - mostFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                // We do NOT recompute mostFreq; stale is okay for correctness.
            }

            // BUG 2: measure window AFTER any shrinking
            maxWindow = max(maxWindow, right - left + 1);
        }
        return maxWindow;
    }
};
