/*
 * solution.c
 *
 *  Created on: 2016年3月24日
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

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return lh > rh ? lh+1 : rh+1;
}
