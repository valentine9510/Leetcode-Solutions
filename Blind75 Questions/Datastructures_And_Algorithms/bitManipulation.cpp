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
unsigned int turn_off_kth_bit ( unsigned int input, unsigned int k);
bool is_power_of_two(unsigned int input);







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

unsigned int turn_off_kth_bit ( unsigned int input, unsigned int k){
    return input & ~(1 << k);
}


bool is_power_of_two(unsigned int input){

}