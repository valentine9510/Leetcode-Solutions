#include <bits/stdc++.h>

using namespace std;


/**
658. Find K Closest Elements
Medium
Topics
Companies
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

 
 * 
 */

/**
 * @brief Plan
 * 
 * 
 * Use a max heap
 *      If size is greater than K
 *          Only add it is less than the top element
 *          Pop top
 * 
 * 
 * 
 * struct CompareVector {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
            return sumOfSquares(b) < sumOfSquares(a); //min heap, we want the smallest values first
        }
    };
 * 
 */

struct CompareVector {
    bool operator()(const int& a, int& b) {
        return (b) < (a); //min heap, we want the smallest values first
    }
};

struct compare_test
{
    bool operator()(const pair<int,int> &a, const pair<int,int>&b){
        if(a.second == b.second)
            return b.first > a.first;
        return b.second > a.second;
    }
};

class Solution {
public:
    struct comparator_custom
    {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if(b.second == a.second)
                return b.first > a.first;
            return b.second > a.second; //max heap, we want the biggest values first
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator_custom> max_heap;
        vector<int> soln;

        //store pair of integer and distance
        //first is integer, second is distance
        for(auto num : arr){
            if(max_heap.size() < k){
                max_heap.push(make_pair(num, abs(num-x)));
            } else {
                max_heap.push(make_pair(num, abs(num-x))); //size must be K+1
                max_heap.pop();
            }
        }

        while (max_heap.empty() == false)
        {
            soln.push_back(max_heap.top().first);
            max_heap.pop();
        }

        sort(soln.begin(), soln.end());

        return soln;        
    }
};