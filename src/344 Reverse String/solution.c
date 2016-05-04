/*
 * solution.c
 *
 *  Created on: 2016年5月4日
 *      Author: wengle
 */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverseString(char* s) {
    int len = strlen(s);
    int i = 0, j = 0;
    for(i = 0, j = len-1; i < j; i++, j--){
        swap(&s[i], &s[j]);
    }
    return s;
}

