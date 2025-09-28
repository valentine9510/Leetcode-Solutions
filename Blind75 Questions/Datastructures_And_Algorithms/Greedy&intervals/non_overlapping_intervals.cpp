#include <bits/stdc++.h>

using namespace std;

/*
Core idea (Greedy = Primary)

To remove the fewest intervals, we want to keep as many non-overlapping intervals as possible.
The maximum number of non-overlapping intervals is achieved by sorting by end time and always picking the interval that finishes earliest (classic activity selection).

Steps:
Sort intervals by end ascending.
Initialize count_kept = 0 and last_end = -inf.
Scan left→right:
If curr.start >= last_end, keep it (count_kept++, update last_end = curr.end).
Else, it overlaps ⇒ skip this one (i.e., this contributes to removals).
Answer = n - count_kept.

Why it works: the interval that ends earliest leaves the most room for future intervals—an exchange argument shows any optimal schedule can be transformed to one that includes the earliest-ending interval without decreasing the count 

Complexity

Sorting: O(n log n)

Single pass: O(n)

Space: O(1) extra (ignoring sort)
*/

#include <bits/stdc++.h>
using namespace std;

// LeetCode 435: return the minimum number of intervals to remove
// so the rest are non-overlapping.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 1) Sort by end time ascending
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1]) return a[1] < b[1];
                 return a[0] < b[0]; // tie-breaker by start (not strictly needed)
             });

        int countKept = 0;
        // Use a sentinel smaller than any possible start.
        // If inputs can be very small, you can use LONG_LONG_MIN and long long.
        int lastEnd = INT_MIN;

        // 2) Greedily keep intervals that start after or at the last kept end
        for (const auto& it : intervals) {
            int curr_start = it[0], curr_end = it[1];
            if (curr_start >= lastEnd) {
                // Non-overlapping with the last chosen one -> keep it
                countKept++;
                lastEnd = curr_end;
            } 
            // else: overlapping -> skip this interval (i.e., we "remove" it)
        }

        // 3) Minimum removals = total - kept
        return (int)intervals.size() - countKept;
    }
};
