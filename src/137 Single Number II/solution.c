/*
 * solution.c
 *
 *  Created on: 2016年3月22日
 *      Author: wengle
 */

/**
 * 因为多了一个循环导致一直没有AC
 */
int singleNumber(int* nums, int numsSize) {
    int i = 0, j = 0, bit[32] = {0}, result = 0;
    for(i = 0; i < 32; i++){
        for(j = 0; j < numsSize; j++){
            bit[i] += ((nums[j] >> i) & 1);
        }
        bit[i] = bit[i] % 3;
        result |= (bit[i]<<i);
    }
//	for(i = 0; i < numsSize; i++){
//		result |= (bit[i]<<i);
//	}
    return result;
}

