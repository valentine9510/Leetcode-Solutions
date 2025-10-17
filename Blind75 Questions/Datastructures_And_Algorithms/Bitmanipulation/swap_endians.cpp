#include <bits/stdc++.h>

/**
 * @brief Reverse order of bytes
 * 
 * @param input 
 * @return unsigned int 
 */
unsigned int swap_endians(unsigned int input){
    unsigned int result;

    unsigned int left_most = (0x000000FF & input) >> 0;
    unsigned int middle_left = (0x0000FF00 & input) >> 8;
    unsigned int middle_right = (0x00FF0000 & input) >> 16;
    unsigned int right_most = (0xFF000000 & input) >> 24;

    result = (left_most << 24) | (middle_left << 16) | (middle_right << 8) | (right_most << 0 );

    return result;
}
