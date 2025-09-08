#include <bits/stdc++.h>
using namespace std;

/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104

*/


/* Plan 

Can use a greedy algorithm

If the total cost > total gas, it would be impossible, so we keep track of those

Next keep track of the tank = tank + gas - cost
if tank < 0, means we cant start at this or any station before this, so start=i+1

*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, startIndex = 0, tank = 0;

        for(int i = 0; i < cost.size(); i++){
            totalCost += cost[i];
            totalGas += gas[i];
            tank = tank + gas[i] - cost[i];

            if(tank < 0){
                startIndex = i+1;
                tank = 0;
            }
        }

        return (totalGas >= totalCost) ? startIndex : -1;
    }
};

// LeetCode 134: Gas Station
// Greedy O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = (int)gas.size();

        long long total = 0;   // total net gas across all stations
        long long tank = 0;    // current tank while scanning
        int start = 0;         // candidate start index

        for (int i = 0; i < n; ++i) {
            long long diff = (long long)gas[i] - (long long)cost[i];
            total += diff;
            tank  += diff;

            // If we can't reach the next station from current candidate start,
            // then any start in [start, i] is invalid. Reset start to i+1.
            if (tank < 0) {
                start = i + 1;
                tank = 0; // reset running tank for the new segment
            }
        }

        // If overall gas is insufficient, no solution.
        if (total < 0) return -1;
        // Otherwise, the greedy start works.
        return (start == n ? 0 : start);
    }
};

//BRUTE FORCE
//See if you can move n steps away from it

/*
Complexity

Time: O(n^2) → for each start (n), simulate n steps.

Space: O(1) → only extra variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // Try every station as starting point
        for (int start = 0; start < n; ++start) {
            int tank = 0;
            bool ok = true;

            // Simulate traveling n steps from this start
            for (int step = 0; step < n; ++step) {
                int cur = (start + step) % n;  // wrap around
                tank += gas[cur] - cost[cur];

                if (tank < 0) {
                    ok = false; // ran out of gas
                    break;
                }
            }

            if (ok) return start; // found valid start
        }

        return -1; // none worked
    }
};
