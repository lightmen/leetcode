/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
struct TreeNode * get_tree(int *inorder,int in_start,int in_end,int *preorder,int pre_start,int pre_end)
{
    struct TreeNode *root = NULL;
    if(in_end - in_start < 0)
        return root;
    int i;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[pre_start];
    root->left = root->right = NULL;
    for(i = in_start; i <= in_end; ++i)
        if(inorder[i] == preorder[pre_start])
            break;
    if(i != in_start)
        root->left = get_tree(inorder,in_start,i - 1,preorder,pre_start + 1,pre_start + i - in_start);
    if(i != in_end)
        root->right = get_tree(inorder,i + 1,in_end,preorder,pre_start + i - in_start + 1,pre_end);
    return root;
}
struct TreeNode *buildTree(int *preorder, int *inorder, int n) {
    return get_tree(inorder,0,n-1,preorder,0,n-1);
}
