/*
 * solution.c
 *
 *  Created on: 2016年3月28日
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

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode *odd = head;
    struct ListNode *even, *temp;
    even = head->next;
    temp = even;
    while(temp != NULL && temp->next != NULL){
        odd->next = odd->next->next;
        temp->next = temp->next->next;
        odd = odd->next;
        temp = temp->next;
    }
    odd->next = even;
    return head;
}
