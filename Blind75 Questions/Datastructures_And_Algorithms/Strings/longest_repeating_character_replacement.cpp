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

/*
Core idea

Use a sliding window (two pointers left and right).

Keep track of how many times each character appears in the current window.

Let maxCount = the count of the most frequent character in the window.

The number of changes needed = windowLength - maxCount.
If this is ≤ k, the window is valid.
If it’s > k, shrink the window from the left.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Count array for 26 uppercase letters
        vector<int> freq(26, 0);

        int left = 0;            // left pointer of the sliding window
        int maxCount = 0;        // most frequent char count in current window
        int longest = 0;         // answer we will return

        // Expand the window by moving `right`
        for (int right = 0; right < (int)s.size(); ++right) {
            // Step 1: include s[right] into the window
            int idx = s[right] - 'A';
            freq[idx]++;
            maxCount = max(maxCount, freq[idx]); // update most frequent char count

            // Step 2: check if window is still valid
            int windowLength = right - left + 1;
            int charsToReplace = windowLength - maxCount;

            if (charsToReplace > k) {
                // Too many replacements needed, shrink from the left
                freq[s[left] - 'A']--;
                left++;
                windowLength = right - left + 1; // update window length
            }

            // Step 3: update answer
            longest = max(longest, windowLength);
        }

        return longest;
    }
};
