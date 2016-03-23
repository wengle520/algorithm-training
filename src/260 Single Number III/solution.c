/*
 * solution.c
 *
 *  Created on: 2016年3月23日
 *      Author: wengle
 */

#include <stdbool.h>

/**
 * 如果对所有元素进行异或操作，最后剩余的结果是出现次数为1次的两个数的异或结果，
 * 此时无法直接得到这两个数具体的值。但是，因为这两个数一定是不同的，
 * 所以最终异或的值至少有一个位为1。我们可以找出异或结果中第一个值为1的位，
 * 然后根据该位的值是否为1，将数组中的每一个数，分成两个部分。这样每个部分，
 * 就可以采用Single number I中的方法得到只出现一次的数。
 * http://www.wengweitao.com/lintcode-single-number-i-ii-iii-luo-dan-de-shu.html
 */

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int result = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++){
        result ^= nums[i];
    }
    int indexOfBit1 = findBit(result);
    int num1 = 0, num2 = 0;
    for(i = 0; i < numsSize; i++){
        if(isBit1(nums[i], indexOfBit1)) {
            num1 ^= nums[i];
        }else{
            num2 ^= nums[i];
        }
    }
    int *ret = malloc(sizeof(int)*2);
    *ret = num1;
    *(ret+1) = num2;
    *returnSize = 2;
    return ret;
}

int findBit(int num){
    int index = 0;
    while((num&1) != 1){
        index++;
        num = num >> 1;
    }
    return index;
}

/**
 * 移动index位后，最低位位1的为一类，为0的为一类
 */
bool isBit(int num, int index){
    num = num >> index;
    return (num & 1);
}
