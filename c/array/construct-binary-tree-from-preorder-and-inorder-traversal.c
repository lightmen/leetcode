/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *helper(int *preorder, int pre_start, int pre_end,
        int *inorder, int in_start, int in_end)
{
    if(in_end < in_start)
        return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[pre_start];

    int mid;
    for(mid = in_start; mid <= in_end; ++mid)
        if(inorder[mid] == preorder[pre_start])
            break;

    root->left = helper(preorder,pre_start+1,pre_start+mid-in_start,inorder,in_start,mid-1);
    root->right = helper(preorder,pre_start+mid-in_start + 1,pre_end,inorder,mid+1,in_end);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(inorderSize == 0)
        return NULL;

    return helper(preorder,0,preorderSize-1,inorder,0,inorderSize-1);
}
