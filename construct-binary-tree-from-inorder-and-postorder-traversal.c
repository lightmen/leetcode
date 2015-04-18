/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
static struct TreeNode *get_tree(int *inorder,int in_start,int in_end,
            int *postorder,int post_start,int post_end)
{
    struct TreeNode *root = NULL;
    if(in_end < in_start)
        return root;
    int i;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[post_end];
    root->left = NULL;
    root->right = NULL;
    for(i = in_start; i <= in_end; ++i)
        if(inorder[i] == postorder[post_end])
            break;
    if(i != in_end)
        root->right = get_tree(inorder,i+1,in_end,postorder,
                post_end - (in_end - i),post_end - 1);
    if(i != in_start)
        root->left = get_tree(inorder,in_start,i-1,postorder,
                post_start,post_end - (in_end - i) - 1);
    return root;
}
struct TreeNode *buildTree(int *inorder, int *postorder, int n) {
    return get_tree(inorder,0,n-1,postorder,0,n-1);
}
