/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Min Stack
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
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

Step-by-Step Explanation
1. Understand the Problem
We need a stack with all the usual stack operations (push, pop, top) plus an additional operation getMin that should return the minimum value currently in the stack.
All operations should run in constant time, i.e., O(1).
2. Naive Approach
You might first think of keeping track of the minimum value using a variable. However, if the minimum value is removed (e.g., via pop()), you lose track of what the next minimum should be. Thus, we need a way to track the minimum values throughout the stack’s history.

3. Optimized Approach
The trick is to use two stacks:

Main Stack: To store all the elements.
Min Stack: To store the minimum values. The top of the min stack always holds the current minimum value of the main stack.
*/

/**
 * @brief Edge cases
 * 
 * 
 * Multiple min values
 * 
 */
class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        //update main stack
        mainStack.push(val);

        //update minStack, use val <= minStack.top() in case you have multiple min values
        if(minStack.empty() || (val <= minStack.top())){
            minStack.push(val);
        }
    }
    
    void pop() {

        //update minStack
        if(minStack.top() == mainStack.top()){
            minStack.pop();
        }

        //update main stack
        mainStack.pop();
    }
    
    int top() {
        //return top element of the stack
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};