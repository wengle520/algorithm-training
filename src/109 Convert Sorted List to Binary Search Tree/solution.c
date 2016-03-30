/*
 * solution.c
 *
 *  Created on: 2016年3月30日
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* helper(int *nums, int left, int right){
    if(left > right){
        return NULL;
    }
    if((right - left) == 0){
        struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
        root->val = nums[left];
        return root;
    }
    int mid = (left + right) / 2;
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = helper(nums, left, mid-1);
    root->right = helper(nums, mid+1, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    int size = 0;
    struct ListNode* temp = head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    int *nums = calloc(size, sizeof(int));
    for(i = 0; i < size && temp != NULL; i++){
        nums[i] = temp->val;
        temp = temp->next;
    }
    return helper(nums, 0, size-1);
}
