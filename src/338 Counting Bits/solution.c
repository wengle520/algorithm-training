/*
 * solution.c
 *
 *  Created on: 2016年3月22日
 *      Author: wengle
 */

#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
	int *result = calloc(num+1, sizeof(int));
	*result = 0;
	*returnSize = 1;
	if(num == 0) return result;
	int i = 1;
	*returnSize = num+1;
	for(; i <= num; i++){
		each_num(i, result+i);
	}
	return result;
}

/**
 * count each i(o<=i<=num)，including the number of 1's
 * in their binary representation
 */
void each_num(int num, int* arr){
	while(num){
		num &= num-1;
		*arr += 1;
	}
}

int main(int argc, char **argv) {
	int *result;
	int size, num = 10, i = 0;
	result = countBits(num, &size);
	printf("%d\n", size);
	for(; i <= num; i++){
		printf("%d\n", result[i]);
	}
}


