/*
 * solution.c
 *
 *  Created on: 2016年4月3日
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *tmp = head;
    int count = 0;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    int flag = count - n;
    if(flag == 0){
        return head->next;
    }
    tmp = head;
    flag--;
    while(flag){
        tmp = tmp->next;
        flag--;
    }
    tmp->next = tmp->next->next;
    return head;
}
