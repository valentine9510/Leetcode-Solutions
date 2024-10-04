/**
 * @file find_missing_number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& nums) {
    int n = nums.size();  // Length of the input list (which should be N)
    int xorAll = 0;
    
    // XOR all the elements in the array
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // XOR all numbers from 0 to N
    for (int i = 0; i <= n; ++i) {
        xorAll ^= i;
    }
    
    // The result is the missing number
    return xorAll;
}

int findMissingNumberSum(const std::vector<int>& nums) {
    int n = nums.size();  // Length of the input list (which should be N)
    
    // Calculate the expected sum of numbers from 0 to N
    int expectedSum = n * (n + 1) / 2;
    
    // Calculate the actual sum of numbers in the array
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    
    // The missing number is the difference between the expected and actual sums
    return expectedSum - actualSum;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 4, 5};  // Example input (missing number is 2)
    int missing = findMissingNumber(nums);
    std::cout << "The missing number is: " << missing << std::endl;
    return 0;
}
