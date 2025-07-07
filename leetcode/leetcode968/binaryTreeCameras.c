
  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

// 0 = sem cobertura
// 1 = tem camera
// 2 = coberto sem camera


int dfs(struct TreeNode* root, int *res){
    if( !root ) return 2;

    int left = dfs(root->left, res);
    int right = dfs(root->right, res);
    
    if( left == 0 || right == 0 ){ // um dos filhos precisa de camera
        (*res)++; 
        return 1;
    } 
    if( left == 1 || right == 1) return 2; // está coberto

    return 0; // precisa de camera
}

int minCameraCover(struct TreeNode* root) {
    int res = 0;
    return (dfs(root, &res) < 1 ? 1 : 0) + res;
}