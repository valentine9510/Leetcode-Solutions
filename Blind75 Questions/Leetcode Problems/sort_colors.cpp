/**
 * @file sort_colors.cpp
 * @author Valentine Roland
 * @brief Sorting Algorithms
 * @version 0.1
 * @date 2024-08-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h> 


using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

class Solution {
public:
    void mergeSort(vector<int>& nums){
        //base case
        if(nums.size() < 2) return;

        //split into half
        vector<int> left;
        vector<int> right;

        for(int i = 0; i < nums.size(); i++){
            if(i < nums.size()/2) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        //mergesort left
        mergeSort(left);
        mergeSort(right);
        merge(left,right,nums);
    }

    void merge(vector<int> &left, vector<int>&right, vector<int>&nums){
        auto left_index = 0;
        auto right_index = 0;
        auto nums_index = 0;

        while (left_index < left.size() && right_index < right.size())
        {
            if(left[left_index] <= right[right_index]){ //left value is smaller
                nums[nums_index] = left[left_index];
                left_index++;
            } else {
                nums[nums_index] = right[right_index];
                right_index++;
            }

            nums_index++;
        }

        //if left is not done
        while (left_index < left.size()){
            nums[nums_index] = left[left_index];
            left_index++;
            nums_index++;
        }

        //if right is not done
        while (right_index < right.size()){
            nums[nums_index] = right[right_index];
            right_index++;
            nums_index++;
        }
        
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums);
    }
};