/*
 * solution.c
 *
 *  Created on: 2016年3月26日
 *      Author: wengle
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = malloc(numsSize*sizeof(int));
    int currentResult = 1, i = 0, index = -1;
    int zeroResult = 1;
    int *temp = result;
    for(i = 0; i < numsSize; i++){
        currentResult *= nums[i];
        if(currentResult == 0){
            index = i;
            break;
        }
    }
    if(index >= 0){
        for(i = 0; i < numsSize; i++){
            if(i != index){
                *(temp+i) = 0;
                zeroResult *= nums[i];
            }
        }
    }
    if(index >= 0){
        *(temp+index) = zeroResult;
        return result;
    }
    for(i = 0; i < numsSize; i++){
        *(temp) = currentResult/nums[i];
        temp++;
    }
    //返回时一定要返回开始的地址，而不是数组末尾的地址
    return result;
}

/**
 * 主要思路是：根据第i个位置，把数组分成两部分，分别计算结果
 * result[i] = left(0<=i<=i-1) * right(i+1<=i<=n)
 */
int* productExceptSelf2(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = malloc(numsSize*sizeof(int));
    int i = 0, right = 1;
    result[0] = 1;
    //left(0<=i<=i-1)
    for(i = 1; i < numsSize; i++){
        result[i] = result[i-1] * nums[i-1];
    }
    //right(i+1<=i<=n)
    for(i = numsSize - 1; i >= 0; i--){
        result[i] *= right;
        right *= nums[i];
    }
    return result;
}
