/*
 * solution.c
 *
 *  Created on: 2016年3月31日
 *      Author: wengle
 */

/**
 * 原理：n! = 2的x幂次*3的y幂次*5的z幂次*...
 * 而尾部的0的个数由2和5的幂次决定，0的个数等于min(x,z)，并且min(x,z)==z
 * min(x,z)==z，证明：[n!/2] > [n!>5]；同时[n!/5]表示1～n中能被5整除的个数,
 * 所以x>z；
 */
int trailingZeroes(int n) {
    int count = 0;
    while(n){
        count += n / 5;
        n /= 5;
    }
    return count;
}
