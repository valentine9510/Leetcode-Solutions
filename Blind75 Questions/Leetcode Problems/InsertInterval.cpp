#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

class Solution {
public:
    /**
     * @brief 
     * Create a solution array
     * Plan, insert all the intervals before
     * if we are in a merging case, we take the 
     *          minimum of the newIntervalStart and currentIntervalStart
     *          max of the newIntervalEnd and endInterValEnd
     * Add all elements after
     * 
     * 
     * @param intervals 
     * @param newInterval 
     * @return vector<vector<int>> 
     */
   vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;


        //case 1, intervals before newInterval
        while(i<intervals.size()  && intervals.at(i).at(1) < newInterval.at(0)){
            answer.push_back(intervals.at(i)); //just add it to solution
            i++;
        }

        while(i<intervals.size()  &&  newInterval.at(1) >= intervals.at(i).at(0)){ //case 2, merging. NewInterval end >= currentInterval start
            newInterval.at(0) = min(intervals.at(i).at(0), newInterval.at(0));
            newInterval.at(1) = max(intervals.at(i).at(1), newInterval.at(1));
            i++;
        }
        answer.push_back(newInterval); //handles empty calse 2


        while(i < intervals.size()){
            answer.push_back(intervals.at(i));
            i++;
        }

        return answer;    
    }
};