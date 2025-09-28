/**
 * @file subsets.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
 Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
 
 */

/**
 * @brief Plan
 * 
 * if(solution is not in our solutions yet ) add it to solution
 * 
 * otherwise
 *      if value is not in current solution
 *          Add it to current solution
 *          Backtrack
 *      Remove value from current solution
 * 
 */


class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<vector<int>>  &answer, vector<int> curr_set) {
        sort(curr_set.begin(), curr_set.end());

        bool already_in_answer = any_of(answer.begin(), answer.end(), [ &curr_set](vector<int>& input){
            return (curr_set == input);
        });

        if(!already_in_answer){
            answer.push_back(curr_set);
        }

        //Go through our choices and add them
        for(int i = 0; i < nums.size(); i++){
            //if not in current solution
            if(find(curr_set.begin(), curr_set.end(), nums[i]) != curr_set.end()) continue; //try something else

            //add to solution
            curr_set.push_back(nums[i]);

            //backtrack
            subsetsHelper(nums, answer, curr_set);

            //remove from solution
            auto new_end = std::remove(curr_set.begin(), curr_set.end(), nums[i]);
            curr_set.erase(new_end, curr_set.end());
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        subsetsHelper(nums, answer, {});

        return answer;
    }
};

/* Compact solution */
class Solution {
    public :
        void subsetsHelper(vector<int>& nums, vector<vector<int>>& answer, vector<int>& curr_set, int start) {
            answer.push_back(curr_set);

            for (int i = start; i < nums.size(); i++) {
                curr_set.push_back(nums[i]); //add to solution
                subsetsHelper(nums, answer, curr_set, i + 1); //backtrack
                curr_set.pop_back();  // remove from solution
            }
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> answer;
            vector<int> curr_set;
            subsetsHelper(nums, answer, curr_set, 0);
            return answer;
        }
};


/* Compact solution */
class Solution {
    public :
    void subset_helper(vector<vector<int>> &soln, vector<int>&nums, vector<int> &curr_vec, int curr_index){
        //If reached goal add to soln
        soln.push_back(curr_vec);

        //Try all new combinations
        for(int i = curr_index; i < nums.size(); i++){
            //add to soln
            curr_vec.push_back(nums[i]);

            //back track
            subset_helper(soln, nums, curr_vec, i+1);

            //remove from soln
            curr_vec.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> soln;
        vector<int> curr_vec;

        subset_helper(soln, nums, curr_vec, 0);

        return soln;
    }
};