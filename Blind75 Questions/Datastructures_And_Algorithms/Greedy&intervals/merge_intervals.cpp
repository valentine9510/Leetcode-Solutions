/**
 * @file merge_intervals.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /* Sort intervals according to start */

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0]; /* Sort according to start times */
        });
        
        vector<vector<int>> soln;

        for(vector<int> &curr_interval : intervals){
            if(soln.empty() || curr_interval[0] > soln.back()[1]) /* For empty solution OR if the new interval is after the older interval */
                soln.push_back(curr_interval);
            else /* Merge time, only compare end times since we already sorted based on start times */
                soln.back()[1] = std::max(soln.back()[1], curr_interval[1] );
        }

        return soln;
    }
};