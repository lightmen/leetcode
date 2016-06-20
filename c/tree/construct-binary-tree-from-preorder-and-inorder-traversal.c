/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *rescan(int *preorder, int left_pre, int *inorder, int left_in, int len)
{
    if(len <= 0)
        return NULL;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    int node_pos = left_in;
    while(node_pos < left_in + len){
        if(inorder[node_pos] == preorder[left_pre])
            break;
        ++node_pos;
    }

    node->val = preorder[left_pre];
    node->left = rescan(preorder, left_pre + 1, inorder, left_in, node_pos - left_in);
    node->right = rescan(preorder, left_pre + 1 + node_pos - left_in, inorder,
            node_pos + 1, len - 1 - (node_pos - left_in));

    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return rescan(preorder, 0, inorder, 0, inorderSize);
}
