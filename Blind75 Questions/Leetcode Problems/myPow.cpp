#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 */

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;

        bool positive = (n > 0);
        double result = 1;
        n = abs(n);
        while (n > 0)
        {
            result *= x;
            n--;
        }
        
        return positive ? result : (1.0/result);
    }
};

//Efficient solution
/*
Exponentiation by squaring computes 
𝑥
𝑛
x 
n
  in logarithmic time by iteratively squaring x and reducing the exponent by half.
When n is negative, the reciprocal is returned.
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        long long power = abs((long long)n);
        double result = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                result *= x;
            }
            x *= x;
            power /= 2;
        }

        return n > 0 ? result : (1.0 / result);
    }
};
