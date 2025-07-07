
 // Definition for a binary tree node.
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

int height(struct TreeNode *node){
    if( !node ){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    if( (left == -1) || (right == -1) || (abs(left - right) > 1) ){
        return -1;
    }
    
    if(left > right){
        return left + 1;
    }
    else{
        return right + 1;
    }
    
}

bool isBalanced(struct TreeNode* root) {
    if( !root ){
        return 1;
    }
    if( height(root) == -1 ){
        return 0;
    }
    
    return 1;
}
