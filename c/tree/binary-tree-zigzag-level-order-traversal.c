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
    int left2right = 0;
    int **arr;
    int arr_size = 64;
    int row = 0;
    int *col_size;
    struct TreeNode **queue;
    int queue_count = 0;
    struct TreeNode **next_queue;
    int next_queue_count= 0;
    int i;

    arr = malloc(sizeof(int *) * arr_size);
    col_size = malloc(sizeof(int) * arr_size);

    queue = malloc(sizeof(struct TreeNode *) * 128);
    next_queue = malloc(sizeof(struct TreeNode *) * 128);

    if(root)
        queue[queue_count++] = root;

    while(queue_count > 0){
        int *ele = malloc(sizeof(int) * queue_count);
        col_size[row] = queue_count;
        for(i = 0; i < queue_count; ++i){
            ele[i] = queue[i]->val;

        }
        for(i = queue_count-1; i >= 0; --i){
            if(left2right){
                if(queue[i]->left)
                    next_queue[next_queue_count++] = queue[i]->left;
                if(queue[i]->right)
                    next_queue[next_queue_count++] = queue[i]->right;
            }else{
                if(queue[i]->right)
                    next_queue[next_queue_count++] = queue[i]->right;
                if(queue[i]->left)
                    next_queue[next_queue_count++] = queue[i]->left;
            }
        }

        arr[row] = ele;
        struct TreeNode **swap = queue;
        queue = next_queue;
        next_queue = swap;

        queue_count = next_queue_count;
        next_queue_count = 0;

        left2right ^= 1;
        row++;
    }

    free(queue);
    free(next_queue);
    *returnSize = row;
    *columnSizes = col_size;
    return arr;
}
