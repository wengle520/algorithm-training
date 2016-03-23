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

/**
 * 在二进制中按位于&相当于相加进位，异或^相当于相加
 */
int singleNumber2(int* nums, int numsSize) {
	int ones = 0, twos = 0, threes = 0, i = 0;
	for(i = 0; i < numsSize; i++){
		//ones & nums[i]得到的是各个位置上的1，出现了两次的结果。
		//twos变量取nums[i]和ones的按位与，用来表示取了他们相加的后进位的位数，
		//自身的按位或用于保留之前处于2阶段的位数
		twos |= ones & nums[i];
		//ones ^ nums[i]按位相加，保留只出现一次1的位数
		ones ^= nums[i];//这一步与上一步不能交换位置，因为是为了保证第一次循环时，
		//twos不会记录两次nums[0]的结果。
		threes = ones & twos;//threes由ones和twos按位相加进位得到，只有两个1相与才能得到1
		ones &= ~threes;//threes取反表示将出现三次1的位数清零了，
		//再和ones按位与得到1的位表示该位没有达到3次1，并且恰好只有1次1
		twos &= ~threes;//threes取反表示将出现三次1的位数清零了，
		//再和twos按位与得到1的位表示该位没有达到3次1，并且恰好只有2次1
	}
	return ones;
}

