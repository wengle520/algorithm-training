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
/**
 * I solve it quickly.So will google employ me? :)
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
