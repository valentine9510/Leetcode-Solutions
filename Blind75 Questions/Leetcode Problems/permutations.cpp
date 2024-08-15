/**
 * @file permutations.cpp
 * @author Valentine Roland
 * @brief Permutations number
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
/*
    We know that we are in a backtracking problem when 
        - We have a state space
        - We have to choose possible solutions
            - Permutations, - n queen
    

    Backtracking recipe 
        void Backtrack( res, args) 
            if ( GOAL REACHED ) 
                add solution to res 
                return 

            for ( int i =0;  i < NB_CHOICES; i++){
                if (CHOICES[i] is valid)
                    make choices[i] (add to current solution)
                    Backtrack( res, args) 
                    undo choices[i] (add to current solution)
            }
                
*/

/*
    Summary:
        Time Complexity: O(N!), where N is the number of elements in the array. This is because there are N! possible permutations.
        Space Complexity: O(N) for the recursion stack and O(N!) for storing the results.
 */

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& solution, vector<int>& nums, vector<int>& permutation, vector<bool>& used){
        //If goal is reached
            //add solution to result
                //result
        if(permutation.size() == nums.size()){
            solution.push_back(permutation);
            return;
        }

        //for choices
            //if choice is valud
                //add choice to current solution
                    //backtrack
                //remove choice from current solution
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false) { //if not used
                used[i] = true; //being used
                permutation.push_back(nums[i]); //add to current solution

                backtrack(solution, nums, permutation, used);

                used[i] = false; //not being used
                permutation.pop_back(); //add to current solution
            }            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used (nums.size(), false); //initialised to false
        vector<int> curr_permutation;
        vector<vector<int>> solution;

        backtrack(solution, nums, curr_permutation, used);

        return solution;
    }
};