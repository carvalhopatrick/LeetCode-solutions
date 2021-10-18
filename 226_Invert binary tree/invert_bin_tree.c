/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// this works:
struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    
    struct TreeNode* invertedL = invertTree(root->left);
    struct TreeNode* invertedR = invertTree(root->right);

	root->left = invertedR;
	root->right = invertedL;

	return root;
}

// this doesnt work: (why???)
/*
struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    
    struct TreeNode* invertedL = invertTree(root->left);
    struct TreeNode* invertedR = invertTree(root->right);

    struct TreeNode* inverted = malloc(sizeof(struct TreeNode));
	inverted->left = invertedR;
	inverted->right = invertedL;

	return inverted;
} 
*/