/*
 * solution.c
 *
 *  Created on: 2016年3月25日
 *      Author: wengle
 */
#include <limits.h>

// 1. discards all leading whitespaces
// 2. sign of the number
// 3. overflow
// 4. invalid input
int myAtoi(char* str) {
    int result = 0;
    int positive = 1;
    // 1. discards all leading whitespaces
    while(*str == ' '){
        str++;
    }
    // 2. sign of the number
    if (*str == '-' || *str == '+') {
        positive = 1 - 2 * (*str == '-');
        str++;
    }
    // 4. invalid input
    while('0' <= *str && *str <= '9'){
    	// 3. overflow
        if(result > (INT_MAX/10) || (result == INT_MAX/10 && (*str-'0') > 7)){
            if(positive == 1){
                return INT_MAX;
            }else{
                return INT_MIN;
            }
        }
        result = result*10 + ((*str++)-'0');
    }
    result *= positive;
    return result;
}
