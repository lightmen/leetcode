/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* rescan(int* inorder, int left_in, int* postorder, int left_post, int len)
{
    if(len <= 0)
        return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    int node_pos = left_in;
    while(node_pos < left_in + len){
        if(inorder[node_pos] == postorder[left_post + len - 1])
            break;
        ++node_pos;
    }

    node->val = postorder[left_post + len - 1];
    node->left = rescan(inorder,left_in,postorder,left_post,node_pos-left_in);
    node->right = rescan(inorder,node_pos+1,postorder,left_post + node_pos - left_in,
            len - 1 - (node_pos - left_in));
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return rescan(inorder, 0, postorder,0,postorderSize);
}
