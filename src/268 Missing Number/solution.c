/*
 * solution.c
 *
 *  Created on: 2016年3月22日
 *      Author: wengle
 */

/**
 * 解法一： 0~N 的和减去数组的和，即得缺失的数
 * 解法二： 求N,利用T^(T^N)=T^T^N=(T^T)^N=0^N=N
 * 与136题类似
 * 这类题的关键点是： 如果给定数组是无序且任意的，一般只能用异或操作完成；
 * 如果给定数组是连续唯一的，可用求和相减或者异或操作完成。
 */
int missingNumber(int* nums, int numsSize) {
    int sum = 0, sumArr = 0, i = 0;
    for(; i < numsSize; i++){
        sumArr += nums[i];
    }
    for(i = 0; i <= numsSize; i++){
        sum += i;
    }
    return (sum - sumArr);

//    int i = 0, temp = 0, sum = 0;
//	for(; i < numsSize; i++){
//		temp ^= nums[i];
//	}
//	for(i = 0; i <= numsSize; i++){
//		sum ^= i;
//	}
//	return sum^temp;
}
