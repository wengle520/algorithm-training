/*
 * solution.c
 *
 *  Created on: 2016年3月26日
 *      Author: wengle
 */
#include <limits.h>
// 例：
// 7÷3 = 2 余 1
// 7÷(-3) = -2 余 1
// (-7)÷3 = -2 余 -1
// (-7)÷(-3) = 2 余 -1

// 可见，余数总是与被除数同号
int reverse(int x) {
    long result = 0;
    while(x){
        result = result*10 + x%10;
        x /= 10;
    }
    return (result < INT_MIN || result > INT_MAX) ? 0 : result;
}
