#include <bits/stdc++.h>
using namespace std;

/*

Code
Testcase
Test Result
Test Result
739. Daily Temperatures
Medium
Topics
Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 */

/**
 * @brief How it Works:
 * 
Initialize answer[] with all zeros.

Use a stack to store indices of days where we are waiting for a warmer temperature.

Iterate through the array temperatures[]:
For each day i, check if the temperature is warmer than the temperature at the index stored in the stack.

If temperatures[i] > temperatures[st.top()], compute the number of days to wait and update answer[prevDay].
    Stack stores the index of every day
    If we find a day that is warmer than the top of the stack
        We update the number of days in the answer array
    
    Those temperatures which will never get a warmer will remain 0, as the answer array is initialized to zero

Continue this until the stack is empty or the current temperature is not warmer.

Push the current day i to the stack.

Return the final answer[].
 * 
 */
 */
/**
 * @brief Go to 
 * 
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int total_size = temperatures.size();
        vector<int> soln (total_size, 0);
        stack<int> store_stack; //monolithic stack

        for(int i = 0; i < temperatures.size(); i++){
            while (store_stack.empty() == false && temperatures[i] > temperatures[store_stack.top()])
            {
                //update all days which meet this warmer day criteria
                int index_to_update = store_stack.top();
                store_stack.pop();

                soln[index_to_update] = i - index_to_update;
            }

            store_stack.push(i); //add to stack and wait for warmer day
            
        }

        return soln;
    }
};