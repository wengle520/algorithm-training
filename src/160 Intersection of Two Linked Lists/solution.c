/*
 * solution.c
 *
 *  Created on: 2016年4月2日
 *      Author: wengle
 */
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmpA = headA;
    struct ListNode *tmpB = headB;
    int countA = 0, countB = 0;
    while(tmpA != NULL){
        countA++;
        tmpA = tmpA->next;
    }
    while(tmpB != NULL){
        countB++;
        tmpB = tmpB->next;
    }
    int flag = countA-countB;
    tmpA = headA;
    tmpB = headB;
    if(flag > 0){
        while(flag){
            tmpA = tmpA->next;
            flag--;
        }
    }else{
        while(flag){
            tmpB = tmpB->next;
            flag++;
        }
    }
    while(tmpA != NULL && tmpB != NULL){
        if(tmpA->val == tmpB->val){
            break;
        }
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    return tmpA;
}
