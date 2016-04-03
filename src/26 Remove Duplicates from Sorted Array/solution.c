/*
 * solution.c
 *
 *  Created on: 2016年3月30日
 *      Author: wengle
 */

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, length = 0;
    for(i = 1; i < numsSize; i++){
        if(nums[i-1] == nums[i]){
            length++;
        }else{
            nums[i-length] = nums[i];
        }
    }
    return numsSize-length;
}
