/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Combination Sum
 * @version 0.1
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool equalVector(vector<int>& left, vector<int>& right){
        unordered_map<int, int> store;

        if(left.size() != right.size()) return false;

        for(int i = 0; i < left.size(); i++){
            store[left[i]]++;
            store[right[i]]--;
        }

        for(auto curr : store){
            if(curr.second != 0) return false;
        }

        return true;        
    }
    void combinationSumHelper(vector<int>& candidates, int target, vector<vector<int>> &final_soln ,vector<int>& curr_soln) {
        //base cases
        if(target < 0) return;
        if(target == 0){
            for(auto i = 0; i < final_soln.size(); i++){
                //only add if it is not in the final solution
                if(equalVector(final_soln.at(i), curr_soln)) return;
            }

            //if it was not part of the final soln, add it
            final_soln.push_back(curr_soln);

            //return
            return;
        }

        for(int i = 0; i < candidates.size(); i++){
            //add to soln
            curr_soln.push_back(candidates[i]);

            //backtrack
            combinationSumHelper(candidates, target-candidates.at(i), final_soln, curr_soln);

            //remove
            curr_soln.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> final_soln;
        vector<int> curr_soln;
        combinationSumHelper(candidates, target, final_soln, curr_soln);

        return final_soln;
    }
};