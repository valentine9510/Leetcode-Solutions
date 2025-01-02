/**
 * @file bitManipulation.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */



/**
 * @brief 
 * 1 - Divide Two Integers
 * 2 - Subsets
 * 3 - Reverse Bits
 * 4 - Subsets II
 * 5 - Gray Code
 * 6 - Single Number II
 * 7 - Repeated DNA Sequences
 * 
 */

//Functions
int swap_Endians(int value);
unsigned int swap_endians_personal(unsigned int input);
bool is_power_of_two(unsigned int input);
unsigned int turn_off_kth_bit ( unsigned int input, unsigned int k);
unsigned int turn_on_kth_bit ( unsigned int input, unsigned int k);
unsigned int toggle_kth_bit ( unsigned int input, unsigned int k);
bool isPowerOfFour(int n);
bool isPowerOfEight(int n);








/**
 * @brief Function to swap a value from 
 * big Endian to little Endian and 
 * vice versa. 
 * 
 * @param value 
 * @return int 
 */
int swap_Endians(int value)
{ 
 
    // This var holds the leftmost 8 
    // bits of the output. 
    int leftmost_byte; 
 
    // This holds the left middle 
    // 8 bits of the output 
    int left_middle_byte; 
 
    // This holds the right middle 
    // 8 bits of the output 
    int right_middle_byte; 
 
    // This holds the rightmost 
    // 8 bits of the output 
    int rightmost_byte; 
 
    // To store the result 
    // after conversion 
    int result; 
 
    // Get the rightmost 8 bits of the number 
    // by anding it 0x000000FF. since the last 
    // 8 bits are all ones, the result will be the 
    // rightmost 8 bits of the number. this will 
    // be converted into the leftmost 8 bits for the 
    // output (swapping) 
    leftmost_byte = (value & 0x000000FF) >> 0; 
 
    // Similarly, get the right middle and left 
    // middle 8 bits which will become 
    // the left_middle bits in the output 
    left_middle_byte = (value & 0x0000FF00) >> 8; 
 
    right_middle_byte = (value & 0x00FF0000) >> 16; 
 
    // Get the leftmost 8 bits which will be the 
    // rightmost 8 bits of the output 
    rightmost_byte = (value & 0xFF000000) >> 24; 
 
    // Left shift the 8 bits by 24 
    // so that it is shifted to the 
    // leftmost end 
    leftmost_byte <<= 24; 
 
    // Similarly, left shift by 16 
    // so that it is in the left_middle 
    // position. i.e, it starts at the 
    // 9th bit from the left and ends at the 
    // 16th bit from the left 
    left_middle_byte <<= 16; 
 
    right_middle_byte <<= 8; 
 
    // The rightmost bit stays as it is 
    // as it is in the correct position 
    rightmost_byte <<= 0; 
 
    // Result is the concatenation of all these values. 
    result = (leftmost_byte | left_middle_byte |
              right_middle_byte | rightmost_byte); 
 
    return result; 
}

/**
 * @brief Reverse order of bytes
 * 
 * @param input 
 * @return unsigned int 
 */
unsigned int swap_endians_personal(unsigned int input){
    unsigned int result;

    unsigned int left_most = (0x000000FF & input) >> 0;
    unsigned int middle_left = (0x0000FF00 & input) >> 8;
    unsigned int middle_right = (0x00FF0000 & input) >> 16;
    unsigned int right_most = (0xFF000000 & input) >> 24;

    result = (left_most << 24) | (middle_left << 16) | (middle_right << 8) | (right_most << 0 );

    return result;
}

/**
 * @brief Turn off Kth bit
 * 
 * @param input 
 * @param k 
 * @return unsigned int 
 */
unsigned int turn_off_kth_bit ( unsigned int input, unsigned int k){
    return input & ~(1 << k);
}

/**
 * @brief Turn on Kth bit
 * 
 * @param input 
 * @param k 
 * @return unsigned int 
 */
unsigned int turn_on_kth_bit ( unsigned int input, unsigned int k){
    return input | (1 << k);
}

/**
 * @brief Toggle Kth bit
 * 
 * @param input 
 * @param k 
 * @return unsigned int 
 */
unsigned int toggle_kth_bit ( unsigned int input, unsigned int k){
    return (input ^ (1 << k));
}

/**
 * @brief Checks if a number is a power of 2
 * 
 * Use brians algorithm
 * 
 * Turn of the last bit using n&(n-1)
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool is_power_of_two(unsigned int input){
    return (input & (input-1)) == 0;
}

/**
 * @brief Function to manually count the number of trailing zeroes
 * 
 * @param n 
 * @return int 
 */
int countTrailingZeros(int n) {
    int count = 0;
    while (n > 0 && (n & 1) == 0) {  // Keep dividing by 2 as long as the least significant bit is 0
        count++;
        n >>= 1;  // Right shift to divide by 2
    }
    return count;
}

/**
 * @brief Checks if an integer is a power of 4
 * Conditions
 *  Trailing zeroes must be a multiple of 2
 *  Must be non zero
 *  Only one bit must be set - must be a power of 2
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPowerOfFour(int n) {
    // Check if the number is greater than 0 and is a power of 2
    if (n > 0 && (n & (n - 1)) == 0) {
        // Count the number of trailing zeros
        int trailingZeros = countTrailingZeros(n);
        // Check if the number of trailing zeros is even
        return (trailingZeros % 2 == 0);
    }
    return false;
}

/**
 * @brief Checks if an integer is a power of 8
 * Conditions
 *  Trailing zeroes must be a multiple of 3
 *  Must be non zero
 *  Only one bit must be set - must be a power of 2
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPowerOfEight(int n) {
    // First, check if the number is greater than 0
    // Then, check if the number is a power of 2 (only one bit is set)
    // Finally, check if the number of trailing zeros is divisible by 3
    if (n > 0 && (n & (n - 1)) == 0) {
        int trailingZeros = countTrailingZeros(n);
        return (trailingZeros % 3 == 0);
    }
    return false;
}






/*

    You are given an array of integers, and the array's size.
    Find a contiguous non-empty subarray within the input array that has the largest product, and return the product.
    
    For example:
    Inputs:
    arr: {-1, 3, 2, -1, -2, 3, 0, -2}
    size: 8
    
    Result: 36
    Explanation: The subarray [3, 2, -1, -2, 3] has a product of 36.

    3 2 -1 -- while

        2 -1 -2 -- remove front, add the next element 

            -1 , -2 , 3

*/

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> input){
    
    // go through all sizes from 1 to size of array

    // for each of those sub arrays, keep track of the largest value
    int result = INT_MIN;

    for(int i = 1; i <= input.size(); i++){
        //deque
        //deque value
        deque<int> sub_array {};
        int deque_total = 1; //multiplier

        int start = 0;
        int end = start+i;

        for(int j = 0; j < input.size()-i; j++){
            if(j < end){ //filling up the deque to subarray size
                deque_total *= input.at(j); 
            } else { //dropping numbers from beginning
                deque_total /= input.at(start); // drop the start value

                start++; // update my start for subarray   012   123

                deque_total *= input.at(j); //multiply by the next value
            }

            //update result
            if(deque_total > result ) result = deque_total;
        }
                
    }

}






