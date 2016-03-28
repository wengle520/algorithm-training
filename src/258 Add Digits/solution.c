/*
 * solution.c
 *
 *  Created on: 2016年3月25日
 *      Author: wengle
 */

int addDigits(int num) {
    int result = 0;
    result = num%9;
    if(num != 0 && result == 0){
        return 9;
    }
    return result;
    // Time Limit Exceeded
    // do{
    //     while(num){
    //         result += num%10;
    //         num /= 10;
    //     }
    //     num = result;
    // }while(result >= 10);
    return result;
}
