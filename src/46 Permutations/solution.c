/*
 * solution.c
 *
 *  Created on: 2016年4月2日
 *      Author: wengle
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void search(int *nums, int numsSize, int ***result, int *returnSize, int begin, int end){
    int i = 0;
    if(begin == end){
        (*returnSize)++;
        (*result) = (int **)realloc(*result, sizeof(int *)*(*returnSize));
        (*result)[*returnSize-1] = (int *)malloc(sizeof(int) * numsSize);
        for(i = 0; i <= end; i++){
            (*result)[*returnSize-1][i] = nums[i];
        }
        return;
    }
    for(i = begin; i <= end; i++){
        swap(nums+begin, nums+i);
        search(nums, numsSize, result, returnSize, begin+1, end);
        swap(nums+begin, nums+i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {

    *returnSize = 0;
    int **result = (int **)calloc(1, sizeof(int *));
    search(nums, numsSize, &result, returnSize, 0, numsSize-1);
    return result;
}
