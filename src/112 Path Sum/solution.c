/*
 * solution.c
 *
 *  Created on: 2016年3月24日
 *      Author: wengle
 */

#include <stdio.h>
#include <stdbool.h>
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

bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL) return false;
    sum -= root->val;
    if(root->left == NULL && root->right == NULL){
        if(sum == 0) return true;
        return false;
    }
    return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
}
