#include <bits/stdc++.h>

using namespace std;

/*
371. Sum of Two Integers
Medium
Topics
Companies
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
*/

/*
    Use bits
    three scenarios

    a b r
    1 1 0/1 
    1 0 1/0
    0 1 1/0
    0 0 0/0
*/

/**
 * @brief 
 * 
 * XOR (^):

Performs addition without considering the carry. If the bits are different, the result is 1 (like adding 1 and 0).
If the bits are the same, the result is 0 (like adding 0 and 0 or 1 and 1 without carrying).
AND (&):

Finds where both bits are 1. This identifies the positions where a carry is needed.
Carry (<< 1):

Shift the carry left by one to move it to the next significant bit for the next addition.
Loop:

Continue the process until the carry is 0 (i.e., no more carry left to add). This ensures the sum is complete.
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carry = 0;
        int bit = 0;

        while (b != 0) {
            int temp = a ^ b;  // Sum without carry
            carry = (a & b) << 1;  // Calculate the carry and shift by one for the next round
            a = temp;
            b = carry;
        }

        return a;
    }
};
