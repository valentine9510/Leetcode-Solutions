#include <bits/stdc++.h>

using namespace std;


/*
735. Asteroid Collision
Medium
Topics
premium lock icon
Companies
Hint
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

/* Going to have a stack as my solution

    Update as I add to the stack

    If I am done, adding asteroids, then update stack

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int a : asteroids) {
            bool destroyed = false;

            // While collision is possible
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                if (abs(a) > abs(stack.back())) {
                    stack.pop_back(); // Right-moving asteroid destroyed
                    continue;         // Keep checking
                } else if (abs(a) == abs(stack.back())) {
                    stack.pop_back(); // Both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Left-moving asteroid destroyed
                    break;
                }
            }

            if (!destroyed)
                stack.push_back(a);
        }

        return stack;
    }
};
