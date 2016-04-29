/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **data;
    int *arr_count;
    int data_count = 500;
    int idx = 0;
    struct TreeNode **cur_st;
    struct TreeNode **next_st;
    int cur_top = -1;
    int next_top = -1;
    int left2right = 0;
    struct TreeNode* cur;

    data = malloc(sizeof(int *) * data_count);
    arr_count = malloc(sizeof(int) * data_count);

    cur_st = malloc(sizeof(struct TreeNode *) * 500);
    next_st = malloc(sizeof(struct TreeNode *) * 500);

    if(root)
        cur_st[++cur_top] = root;

    while(cur_top > -1){
        int c = 0;
        struct TreeNode **swap;

        next_top = -1;
        data[idx] = malloc(sizeof(int) * data_count);
        while(cur_top > -1){
            cur = cur_st[cur_top--];
            data[idx][c++] = cur->val;
            if(left2right){
                if(cur->right)
                    next_st[++next_top] = cur->right;
                if(cur->left)
                    next_st[++next_top] = cur->left;
            }else{
                if(cur->left)
                    next_st[++next_top] = cur->left;
                if(cur->right)
                    next_st[++next_top] = cur->right;
            }
        }
        arr_count[idx] = c;
        idx++;
        left2right ^= 1;

        swap = cur_st;
        cur_st = next_st;
        next_st = swap;

        cur_top = next_top;
    }

    *columnSizes = arr_count;
    *returnSize = idx;

    free(cur_st);
    free(next_st);
    return data;
}
