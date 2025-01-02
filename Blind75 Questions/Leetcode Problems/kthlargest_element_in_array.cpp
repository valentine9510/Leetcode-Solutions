#include <bits/stdc++.h>

using namespace std;


/**
 * @brief 
 * 
 * 215. Kth Largest Element in an Array
Medium
Topics
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 * 
 */


/**
 * @brief Use a priority queue of that size, if we are adding a value which is smaller than the smallest element in the queue
 *  just dont add ti
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(auto curr_num : nums){
            if(min_heap.size() < k){
                min_heap.push(curr_num);
            } else {
                if(curr_num > min_heap.top()){ //only add if it bigger than min
                    //size is already filled
                    min_heap.pop();
                    min_heap.push(curr_num);
                }
            }
        }

        return min_heap.top(); //top of the heap is the Kth smallest element
    }
};