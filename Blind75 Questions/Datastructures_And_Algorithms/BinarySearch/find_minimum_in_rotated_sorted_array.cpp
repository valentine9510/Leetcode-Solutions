#include <bits/stdc++.h>

using namespace std;

/*
    Key idea
    For a rotated, strictly increasing array (no duplicates), the minimum sits at the rotation pivot.
    Use binary search comparing the middle element to the rightmost element:

    If nums[mid] > nums[r]: the minimum is to the right of mid → l = mid + 1.
    Else (nums[mid] < nums[r]): the minimum is at mid or to the left → r = mid.
    
    Maintain a half-open or closed interval invariant consistently:
    I’ll use closed interval [l, r] with loop while (l < r).

    Why compare to nums[r]?
    Because the right half (from pivot to end) is sorted; if nums[mid] > nums[r], mid is in the left rotated chunk; otherwise mid is in the sorted tail that contains the min.

    Edge cases to keep in mind
    Already sorted (no rotation), e.g. [1,2,3] → min is nums[0].
    Single element, e.g. [10].
    Rotation near ends, e.g. [2,3,4,5,1], [5,1,2,3,4].
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = (int)nums.size() - 1;

        // Invariant: minimum lies within [low, high]
        while (low < high) {
            int mid = low + (high - low) / 2; // avoid overflow

            // If mid > high, the min is strictly to the right of mid
            // because the right segment is the rotated (smaller) part.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                // nums[mid] < nums[high]
                // min is at mid or to its left; shrink right boundary
                high = mid;
            }
        }

        // low == high points to the minimum
        return nums[low];
    }
};
