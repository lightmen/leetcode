/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */

int get_max(struct TreeNode *root,int *max){
    if(root == NULL)
        return 0;

    int left = get_max(root->left,max);
    int right = get_max(root->right,max);
    int ret;
    int tmp;
        
    ret = root->val > root->val + left ? root->val : root->val + left;
    ret = ret > root->val + right ? ret : root->val + right;
    
    tmp = root->val + left + right;
    *max = tmp > *max ? tmp : *max;
    
    return ret < 0 ? 0 : ret;
}

int maxPathSum(struct TreeNode *root) {
    int max = INT_MIN;
    get_max(root,&max);
    return max;
}
