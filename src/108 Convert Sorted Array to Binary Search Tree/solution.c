/*
 * solution.c
 *
 *  Created on: 2016年3月30日
 *      Author: wengle
 */
#include <stdio.h>
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

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int low = 0, high = numsSize-1;
    return helper(nums, low, high);
}

