/*
 * solution.c
 *
 *  Created on: 2016年3月22日
 *      Author: wengle
 */
/**
 * ^ operation can select single number
 * 0^N = N or N ^ N = 0
 * 异或运算满足交换律、结合律
 */
int singleNumber(int* nums, int numsSize) {
    int i = 0, result = 0;
    for(; i < numsSize; i++){
        result ^= nums[i];
    }
    return result;
}
