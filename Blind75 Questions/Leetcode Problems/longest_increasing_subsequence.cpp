#include <bits/stdc++.h>

using namespace std;


/**
 * @brief 
 * 
 * 
 * Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?



You are given an integer array nums.
👉 You need to return the length of the longest strictly increasing subsequence in nums.

What does that mean?

A subsequence is not the same as a subarray:

Subarray → contiguous elements (must be next to each other).
Subsequence → you can skip elements, but order must stay the same.
 */

/**
 * @brief Use dp
 * 
 * 
 * start from first element
 *  for any element that we find that is larger
 *      We do dp to find the longest length
 * 
 * 
 * The sub array keeps the largest array we have seen up to that point!
 * 
 * 
 * ChatGPT said:

Exactly 👍 now that you see how it works, the natural next step is:

👉 What is the goal of maintaining sub and doing binary search?

Goal of sub

sub is not the LIS itself.

Instead, sub[len-1] = the smallest possible tail of an increasing subsequence of length len.

This is the patience sorting trick:

By keeping the smallest tail possible for every subsequence length, we leave the most “room” for future numbers to extend it.

Smaller tails = more flexibility to grow longer subsequences.

Why binary search?

At each step, we need to figure out:

Can this new number extend the LIS? (append at the end).

Or should it improve an existing subsequence tail? (replace inside sub).

Since sub is kept sorted, we can find that position quickly using binary search:

pos = lower_bound(sub.begin(), sub.end(), x)

If pos == sub.size() → append (new longer subsequence found).

Else → replace sub[pos] = x (improve tail).

This guarantees that:

sub always stays sorted (so binary search is valid).

The length of sub equals the length of the LIS so far.

Analogy

Think of each number as a “card” you’re stacking:

Each pile (length in sub) ends with a certain top card (the tail).

Binary search finds which pile this new card can go on (replace the top with smaller one if possible).

If no pile fits, you start a new pile (append).

The total number of piles at the end = LIS length.

✅ So the goal:
sub is a compressed record of the “best tails” we can achieve for subsequences of each length, and binary search is the fast way to place each new number into the right spot.

Would you like me to also show you why the size of sub is always equal to LIS length (formal intuition/proof)? That’s usually the part interviewers love to test.

You said:
yes
ChatGPT said:

Perfect — let’s prove why the size of sub = LIS length.
This is the heart of the algorithm, and interviewers love it because it shows you understand the why, not just the how.

Step 1: What sub[k] means

At any point:

sub[k] stores the smallest possible tail value of an increasing subsequence of length k+1.

This doesn’t mean sub itself is the LIS, but it means:

There exists at least one subsequence of length k+1 ending with sub[k].

And you can’t get a smaller tail for a subsequence of that length.

Step 2: Why is sub length a lower bound for LIS length?

Every time we append to sub, it means we discovered a longer increasing subsequence than before.
So the size of sub always tracks the longest length we’ve found so far.
Thus:

len(sub) ≤ LIS length

Step 3: Why can’t sub be shorter than LIS length?

Suppose the true LIS length is L.
We will process the LIS’s elements one by one.

The first element of LIS will start at sub[0].

The second element will either extend (append) or replace something, but guarantees sub[1] exists.

By continuing this way, when we reach the LIS’s last element, we must have grown sub to at least length L.

So:

len(sub) ≥ LIS length

Step 4: Put together

From step 2 and step 3:

len(sub) ≤ LIS length
len(sub) ≥ LIS length
→ len(sub) == LIS length

Intuitive Analogy (Patience Sorting / Card Piles)

Imagine dealing cards into piles:

Place each card onto the leftmost pile with a top card ≥ it (binary search).

If no such pile exists, start a new pile.

The number of piles at the end = LIS length.

Why? Because you cannot build a longer subsequence than the number of piles, and the piles simulate one.

✅ Conclusion:
sub isn’t the LIS itself, but its size always equals the LIS length.

Replacements shrink tails (more options for future growth).

Appends increase the length (new longer subsequence).
That’s why the binary search method works in O(n log n).

Do you want me to also walk you through a small example proof with the actual LIS inside it (like [10, 9, 2, 5, 3, 7, 101, 18]) to show how LIS and sub stay in sync?
 * 
 */
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> sub;

        for (int num : nums) {
            int left = 0, right = sub.size();
            
            // Perform binary search manually
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sub[mid] >= num) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            // If left is at the end, append to sub
            if (left < sub.size()) {
                sub[left] = num;
            } else {
                sub.push_back(num);
            }
        }
        return sub.size();
    }

};


#include <bits/stdc++.h>
using namespace std;

// Returns length of LIS and also writes one actual LIS into `lis_seq`.
int lengthOfLIS_withSequence(const vector<int>& nums, vector<int>& lis_seq) {
    int n = (int)nums.size();
    if (n == 0) { lis_seq.clear(); return 0; }

    // tails[k] is the value of the smallest tail of any increasing subsequence of length k+1
    // tails_idx[k] is the INDEX in nums of that tail
    vector<int> tails;
    vector<int> tails_idx;          // indices in the original array for tails
    vector<int> prev_idx(n, -1);    // predecessor indices to reconstruct the sequence

    tails.reserve(n);
    tails_idx.reserve(n);

    for (int i = 0; i < n; ++i) {
        // For STRICTLY increasing subsequence, we use lower_bound (first >= nums[i]).
        // If we used upper_bound, we'd allow equal elements (non-decreasing).
        int pos = (int)(lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin());

        if (pos == (int)tails.size()) {
            // Extend the longest subsequence
            tails.push_back(nums[i]);
            tails_idx.push_back(i);
        } else {
            // Improve an existing subsequence tail to a smaller value
            tails[pos] = nums[i];
            tails_idx[pos] = i;
        }

        // Link to predecessor (the end index of the subsequence of length pos)
        // For pos == 0, there is no predecessor
        if (pos > 0) {
            prev_idx[i] = tails_idx[pos - 1];
        }
    }

    // Reconstruct one LIS by backtracking from the index that ends the best length
    int lis_len = (int)tails.size();
    lis_seq.resize(lis_len);

    int cur = tails_idx[lis_len - 1];
    for (int k = lis_len - 1; k >= 0; --k) {
        lis_seq[k] = nums[cur];
        cur = prev_idx[cur];
    }

    return lis_len;
}

// LeetCode function that only needs the length
int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    return lengthOfLIS_withSequence(nums, seq);
}

// Example usage / driver (not part of LeetCode submission):
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> seq;
    int len = lengthOfLIS_withSequence(nums, seq);
    cout << "LIS length = " << len << "\n";
    cout << "One LIS: ";
    for (int x : seq) cout << x << " ";
    cout << "\n";
    return 0;
}
