/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *bcreate(int *nums, int start, int end)
{
    if(end < start)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = nums[mid];
    node->left = bcreate(nums, start, mid - 1);
    node->right = bcreate(nums, mid + 1, end);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return bcreate(nums,0,numsSize - 1);
}
