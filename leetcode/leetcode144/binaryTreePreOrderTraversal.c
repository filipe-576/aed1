
// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 // Note: The returned array must be malloced, assume caller calls free().

typedef struct TreeNode Node;
void traverse( Node *node, int **nums, int *top ){
    if( !node ){
        return;
    }

    (*nums)[++(*top)] = node->val;
    if(node->left){
        traverse(node->left, nums, top);
    }
    if(node->right){
        traverse(node->right, nums, top);
    }
    
    
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *nums = (int*) malloc(sizeof(int) * 100);
    int top = -1;
    traverse(root, &nums, &top);
    *returnSize = top+1;
    return nums;
}