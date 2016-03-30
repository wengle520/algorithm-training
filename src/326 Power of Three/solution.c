/*
 * solution.c
 *
 *  Created on: 2016年3月29日
 *      Author: wengle
 */
#include <stdbool.h>
bool isPowerOfThree(int n) {
    if(n <= 0){
        return false;
    }
    double r = log10(n)/log10(3);
    return fabs(r - round(r)) < 1e-13;
}
