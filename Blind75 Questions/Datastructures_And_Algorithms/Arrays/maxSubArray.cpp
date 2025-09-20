/**
 * @file maxSubArray.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
@brief Effecient solution
We start by initializing two variables: maxSum and currentSum.
maxSum represents the maximum sum encountered so far and is initially set to the minimum possible integer value 
to ensure that any valid subarray sum will be greater than it.

currentSum represents the current sum of the subarray being considered and is initially set to 0.

We iterate through the nums array using a for loop, starting from the first element and going up to the last element.

For each element in the array, we add it to the current sum currentSum. This calculates the sum of the subarray ending at the current element.

Next, we check if the current sum currentSum is greater than the current maximum sum maxSum.

If it is, we update maxSum with the new value of currentSum. This means we have found a new maximum subarray sum.

If the current sum currentSum becomes negative, it indicates that including the current element in the subarray would reduce the overall sum. 

In such cases, we reset currentSum to 0. This effectively discards the current subarray and allows us to start a fresh subarray from the next element.
We repeat steps 3 to 5 for each element in the array.

After iterating through the entire array, the variable maxSum will contain the maximum subarray sum encountered.

Finally, we return the value of maxSum as the result, representing the maximum sum of a contiguous subarray within the given array nums.

https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d

"local_maximum at index i is the maximum of A[i] and the sum of A[i] and local_maximum at index i-1."

Consider the array [-8, -3, -6, -2, -5, -4].

Initialize: max_current = -8, max_global = -8
Iteration:
i = 1: max_current = max(-3, -8 + -3) = -3, max_global = max(-8, -3) = -3
i = 2: max_current = max(-6, -3 + -6) = -6, max_global = max(-3, -6) = -3
i = 3: max_current = max(-2, -6 + -2) = -2, max_global = max(-3, -2) = -2
i = 4: max_current = max(-5, -2 + -5) = -5, max_global = max(-2, -5) = -2
i = 5: max_current = max(-4, -5 + -4) = -4, max_global = max(-2, -4) = -2

Example
Consider the array [-2, 1, -3, 4, -1, 2, 1, -5, 4].

Initialize: max_current = -2, max_global = -2
Iteration:
i = 1: max_current = max(1, -2 + 1) = 1, max_global = max(-2, 1) = 1
i = 2: max_current = max(-3, 1 - 3) = -2, max_global = max(1, -2) = 1
i = 3: max_current = max(4, -2 + 4) = 4, max_global = max(1, 4) = 4
i = 4: max_current = max(-1, 4 - 1) = 3, max_global = max(4, 3) = 4
i = 5: max_current = max(2, 3 + 2) = 5, max_global = max(4, 5) = 5
i = 6: max_current = max(1, 5 + 1) = 6, max_global = max(5, 6) = 6
i = 7: max_current = max(-5, 6 - 5) = 1, max_global = max(6, 1) = 6
i = 8: max_current = max(4, 1 + 4) = 5, max_global = max(6, 5) = 6
Result: The maximum sum of the contiguous subarray is 6.
 * 
 * @param nums 
 * @return int 
 */

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& A) {
    int max_local = A[0];
    int max_global = A[0];

    for (size_t i = 1; i < A.size(); ++i) {
        max_local = std::max(A[i], max_local + A[i]); //either the higher of the new_value OR the curr_sub_array_sum + new_value
        max_global = std::max(max_global, max_local);
    }
    return max_global;
}