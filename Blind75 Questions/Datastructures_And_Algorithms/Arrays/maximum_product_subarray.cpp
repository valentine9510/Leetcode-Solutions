#include <bits/stdc++.h>

using namespace std;

/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer
*/

/*
    Key Concept:
        This problem is similar to Kadane’s Algorithm (Maximum Subarray Sum), but multiplication introduces additional challenges:
        A negative number can become positive if multiplied by another negative.
        A zero resets the product.
        A positive number keeps the product growing.

    Approach:
        Track both the maximum product and the minimum product at each position.
        The minimum product is important because multiplying two negative values can yield a larger positive product.

    Step-by-Step Breakdown:
    Initialize Key Variables:

    max_prod = nums[0] → The maximum product so far.
    min_prod = nums[0] → The minimum product so far (in case of negative products).
    result = nums[0] → The final result to track the global maximum.
    Iterate Through the Array (starting from index 1):

    For each element, calculate three values:
    nums[i] (taking current element alone).
    nums[i] * max_prod (continuing the current maximum product).
    nums[i] * min_prod (continuing the current minimum product).
    Update max_prod and min_prod by picking the maximum and minimum of these three values.
    Update the Global Maximum (result) by comparing it with max_prod at each step.
*/

int maxProduct(vector<int>& nums) {
    int min_product = nums[0];
    int max_product = nums[0];
    int result = nums[0];

    for(int i = 1; i < nums.size(); i++){
        
        if(nums[i] < 0)
            std::swap(min_product, max_product);
        
        //try to get global max and min
        min_product = std::min(nums[i], nums[i]*min_product); //this handles the zero case too
        max_product = std::max(nums[i], nums[i]*max_product);

        result = std::max(result, max_product);
    }

    return result; //max product will always hold the bigger number
}



int maxProduct(vector<int>& nums) {
    int min_prod = nums[0];
    int max_prod = nums[0];
    int result = nums[0];

    for(auto curr : nums){
        if(curr < 0)
            std::swap(min_prod, max_prod);
        
        min_prod = std::min(min_prod, min_prod*curr);
        max_prod = std::min(max_prod, max_prod*curr);

        result = std::max(result, max_prod);
    }

    return result;
}




























int maxProduct(vector<int>& nums) {
    int n = nums.size();
    
    int max_prod = nums[0];  // Max product so far
    int min_prod = nums[0];  // Min product so far
    int result = nums[0];    // Final result
    
    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            // Swap max and min if the current element is negative
            std::swap(max_prod, min_prod);
        }
        
        // Update max and min products
        max_prod = std::max(nums[i], nums[i] * max_prod);
        min_prod = std::min(nums[i], nums[i] * min_prod);
        
        // Update the result (global maximum)
        result = std::max(result, max_prod);
    }
    
    return result;
}