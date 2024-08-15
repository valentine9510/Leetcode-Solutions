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

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief Plan 
 * Brute force n^3
 * 
 * More effecient
 * Sort input array to avoid duplicates nLogn
 * Set first value to beginning
 * Use a Left pointer and right pointer to find a sum that = 0
 * 
 * ChatGPT Explanation
 * 
 * Problem Statement
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Approach
 * 1. Sort the Array: Sorting helps to avoid duplicate triplets and simplifies the problem of finding triplets that sum to zero.
 * 2. Iterate with a Fixed Point: Fix one number and use a two-pointer approach to find the other two numbers that sum to zero.
 * 3. Two-Pointer Technique: For the remaining part of the array (after the fixed number), use two pointers: one starting from the next element (left pointer) and one from the end (right pointer).
 * 4. Avoid Duplicates: Skip duplicate numbers to ensure all triplets are unique.
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> soln;
        sort(nums.begin(), nums.end()); //sort in ascending order

        for(int i = 0; i < nums.size(); i++){
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i+1; //two pointer solution
            int right = nums.size()-1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; //get sum
                if (sum == 0) {
                    soln.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    //update left and right pointers
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }

        }

        return soln;
            
    }
};

int main(){
    Solution soln;
    return 0;
}

vector<vector<int>> threeSumInefficient(vector<int>& nums) {
    // vector<vector<int>> soln;

    // for(auto i = 0; i < nums.size(); i++){
    //     for(auto j = 0; j < nums.size(); j++){
    //         for(auto k = 0; k < nums.size(); k++){
    //             if(i != j && i !=k && j!=k && nums[i]+nums[j]+nums[k] == 0){
    //                 vector<int> temp = {nums[i], nums[j], nums[k]};
    //                 sort(temp.begin(), temp.end());

    //                 if(std::find(soln.begin(),soln.end(),temp) == soln.end()){
    //                     soln.push_back(temp);
    //                 }  
    //             }
    //         }
    //     }
    // }

    //

    //return soln;
}