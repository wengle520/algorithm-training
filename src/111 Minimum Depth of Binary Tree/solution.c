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

int minDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    //下面的两个判断是为了区别出现单支树的情况，这时候需要考虑不空的那个分支
    if(lh < rh && (root->left == NULL && root->right != NULL)){
        return rh+1;
    }
    if(rh < lh && (root->right == NULL && root->left != NULL)){
        return lh+1;
    }
    return lh < rh ? lh+1 : rh+1;
}
