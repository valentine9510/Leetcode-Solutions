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
        //Sort the intervals in ascending order based on start times 
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a,const vector<int> &b){
            return a[0] < b[0];  // Compare the first elements of the vectors
        });

        vector<vector<int>> Solution;

        for(int i = 0; i < intervals.size(); i++){
            if(i == 0) {
                Solution.push_back(intervals.at(i));
                continue;
            }

            //Merging happens when the end of the solution.back.end >= intervals[i][start]
            //Just update the last part of the solution as it is a merge
            if(Solution.back().at(1) >= intervals.at(i).at(0)){
                //Merging time
                
                //Start time is the least of the 2 starts
                Solution.back().at(0) = std::min(Solution.back().at(0), intervals.at(i).at(0));

                //End time is the max of the 2 ends
                Solution.back().at(1) = std::max(Solution.back().at(1), intervals.at(i).at(1));
            } else {
                //Cant merge so add it to the solution
                Solution.push_back(intervals.at(i));
            }
        }

        return Solution;
    }
};