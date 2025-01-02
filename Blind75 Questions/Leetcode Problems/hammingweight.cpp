#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * 
 */

/**
 * @brief Given a positive integer n, write a function that returns the number of 
set bits
 in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

Constraints:

1 <= n <= 231 - 1
 

Follow up: If this function is called many times, how would you optimize it?
 * 
 */

class Solution {
public:
    int hammingWeight(int val){
        int counter = 0;

        while (val > 0)
        {
            val = val&(val-1); //unset right most bit
            counter++;
        }
        

        return counter;
    }
};