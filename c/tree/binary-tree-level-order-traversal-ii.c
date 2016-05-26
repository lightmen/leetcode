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
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **arr;
    int *col;
    struct TreeNode **q;
    struct TreeNode **new_q;
    struct TreeNode **cur;
    int arr_count = 8;
    int idx = 0;
    int q_count = 512;
    int tmp_count = 8;
    int i,j;

    arr = malloc(sizeof(int *) * arr_count);
    col = malloc(sizeof(int) * arr_count);
    q = malloc(sizeof(struct TreeNode *) * q_count);
    new_q = malloc(sizeof(struct TreeNode *) * q_count);

    q[0] = root;
    q[1] = NULL;
    while(*q){
        int *tmp;
        i = 0;
        j = 0;
        cur = q;
        memset(new_q, 0, sizeof(struct TreeNode *) * q_count);
        tmp = malloc(sizeof(int) * tmp_count);
        while(*cur){
            if(i == tmp_count){
                tmp_count <<= 1;
                tmp = realloc(tmp, sizeof(int) * tmp_count);
            }
            tmp[i++] = (*cur)->val;
            if((*cur)->left)
                new_q[j++] = (*cur)->left;
            if((*cur)->right)
                new_q[j++] = (*cur)->right;

            cur++;
        }

        if(idx == arr_count){
            arr_count <<= 1;
            col = realloc(col, sizeof(int) * arr_count);
            arr = realloc(arr,sizeof(int *) * arr_count);
        }

        col[idx] = i;
        arr[idx++] = tmp;

        cur = new_q;
        new_q = q;
        q = cur;
    }

    i = 0;
    j = idx - 1;
    while(i < j){
        int *swap = arr[i];
        int swap_col = col[i];

        arr[i] = arr[j];
        arr[j] = swap;

        col[i] = col[j];
        col[j] = swap_col;
        i++;
        j--;
    }

    *columnSizes = col;
    *returnSize = idx;
    free(q);
    free(new_q);

    return arr;
}
