/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Leetcode product of array except self
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

using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

Step-by-Step Explanation
1. Understand the Problem
For each element at index i, we need to calculate the product of all elements in the array except the one at i.
Without using division, the naive approach would be to use two loops, but that would result in O(n^2) time complexity, which is inefficient.
2. Prefix and Suffix Products
To achieve O(n) time complexity, we can use the concept of prefix and suffix products:

Prefix product for an index i is the product of all elements before i.
Suffix product for an index i is the product of all elements after i.

3. Calculate Prefix Products
First, we create an array prefix where prefix[i] contains the product of all elements before index i.
For example, if nums = [1,2,3,4], the prefix product array will look like this:
prefix = [1, 1, 2, 6]

4. Calculate Suffix Products and Combine with Prefix
Next, we traverse the array from right to left to calculate the suffix products and multiply them with the prefix products stored in answer:
Let’s break down what’s happening in the second loop:

We start with suffix = 1.
For each element i from the end of the array:
Multiply answer[i] (which contains the prefix product) by suffix (the suffix product).
Update suffix to include nums[i].
For nums = [1,2,3,4], the final output is calculated as:

answer = [1*24, 1*12, 2*4, 6*1] = [24, 12, 8, 6]

*/

/**
 * @brief Plan
 * 
 *  Keep and array of prefixes and suffixes
 * 
 */

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix (nums.size(), 0);
    vector<int> ans (nums.size(),0);

    long long prefix_total = 1;
    long long suffix_total = 1;

    for(int i = 0; i < nums.size(); i++){
        prefix[i] = prefix_total;
        prefix_total *= nums[i];
    }

    for(int i = nums.size()-1; i >= 0; i--){
        ans[i] = prefix[i]*suffix_total;
        suffix_total *= nums[i];
    }

    return ans;
}






/**
 * @brief Personal trial unoptimised
 * 
 * @param nums 
 * @return vector<int> 
 */
vector<int> productExceptSelf(vector<int>& nums) {
    //Create prefix products, multiplication of all the numbers before the index
    vector<int> prefix (nums.size(), 1); //initialise to 1
    for(int i = 1; i < nums.size(); i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }

    //Create suffix products, mutiplication of all the numbers before the index
    vector<int> suffix (nums.size(), 1);
    for(int i = nums.size()-2; i >= 0; i--){
        suffix[i] = suffix[i+1]*nums[i+1];
    }

    //return the product
    vector<int> answer (nums.size(), 1);
    for(int i = 0; i < nums.size(); i++){
        answer[i] = prefix[i]*suffix[i];
    }

    return answer;
}

/**
 * @brief Personal trial optimised
 * 
 * @param nums 
 * @return vector<int> 
 */
vector<int> productExceptSelf(vector<int>& nums) {
    //Create prefix products, multiplication of all the numbers before the index
    vector<int> prefix (nums.size(), 1); //initialise to 1
    for(int i = 1; i < nums.size(); i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }

    //Create suffix products, mutiplication of all the numbers before the index
    int suffix = 1;
    for(int i = nums.size()-1; i >= 0; i--){
        prefix[i] = prefix[i]*suffix;
        suffix = suffix*nums[i];
    }

    return prefix;
}