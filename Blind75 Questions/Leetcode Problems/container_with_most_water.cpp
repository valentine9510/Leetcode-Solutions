/**
 * @file container_with_most_water.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int low=0;
        int high=height.size()-1;
        
        while (low < high)
        {
            int newSize = std::abs(high-low)* std::min(height[low], height[high]);
            result = std::max(newSize, result);

            //Update pointers
            if(height[low] <  height[high]) low++;
            else high--;
        }

        return result;
        
    }
};