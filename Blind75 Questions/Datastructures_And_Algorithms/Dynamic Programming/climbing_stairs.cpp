#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> climbStairs_pathways;
    int climbStairs(int n) {
        if(climbStairs_pathways.find(n) != climbStairs_pathways.end())
            return climbStairs_pathways[n];
        if(n == 1) return n;
        if(n <= 0) return 0;

        climbStairs_pathways[n] = climbStairs_pathways[n-1] + climbStairs_pathways[n-2];

        return climbStairs_pathways[n];
    }
};