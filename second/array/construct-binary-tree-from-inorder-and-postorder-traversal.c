/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *helper(int *inorder, int in_start, int in_end,
    int *postorder, int post_start, int post_end)
{
    if(in_end < in_start)
        return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[post_end];

    int mid;
    for(mid = in_start; mid <= in_end; ++mid)
        if(inorder[mid] == postorder[post_end])
            break;

    root->left = helper(inorder,in_start,mid-1,postorder,post_start,post_start+mid-in_start-1);
    root->right = helper(inorder,mid+1,in_end,postorder,post_start+mid-in_start,post_end-1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize == 0)
        return NULL;
    return helper(inorder,0,inorderSize-1,postorder,0,postorderSize-1);
}
