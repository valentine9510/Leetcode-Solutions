#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge Case: Handle overflow for INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of result
        bool positive = (dividend > 0) == (divisor > 0);
        
        // Use long long to avoid overflow when converting abs
        long long abs_dividend = abs((long long)dividend);
        long long abs_divisor = abs((long long)divisor);
        long long result = 0;

        // Perform division using bitwise shifting
        while (abs_dividend >= abs_divisor) {
            long long temp = abs_divisor;
            long long multiple = 1;
            
            // Double the divisor until it exceeds the dividend
            while ((temp << 1) <= abs_dividend) {
                temp <<= 1;
                multiple <<= 1;
            }

            abs_dividend -= temp;
            result += multiple;
        }

        // Apply the sign
        return positive ? result : -result;
    }
};
