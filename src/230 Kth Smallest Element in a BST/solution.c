/*
 * solution.c
 *
 *  Created on: 2016年3月29日
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

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int kthSmallest(struct TreeNode* root, int k) {
	//相当于struct TreeNode *sortNode[1000] ==>sortNode是一个数组，
	//数组的长度是1000，数组的每个元素是struct TreeNode*类型
    struct TreeNode **sortNode = (struct TreeNode **)calloc(1000, sizeof(struct TreeNode*));
    int result = 0 ,count = 0, i = 0;
    while(count < k){
        if(root != NULL){
            sortNode[i++] = root;
            root = root->left;
        }else{
            root = sortNode[--i];
            count++;
            root = root->right;
        }
    }
    result = (sortNode[i])->val;
    return result;
}

// void getSortNode(struct TreeNode* root, struct TreeNode *sortNode){
//     if(root == NULL){
//         return;
//     }
//     if(root->left != NULL){
//         getSortNode(root->left, sortNode);
//     }
//     sortNode[i].val = root->val;
//     i++;
//     if(root->right != NULL){
//         getSortNode(root->right, sortNode);
//     }
// }
