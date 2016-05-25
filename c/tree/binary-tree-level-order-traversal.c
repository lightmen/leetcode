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
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **arr;
    int *col_arr;
    int i,j;
    struct TreeNode **q;
    struct TreeNode **new_q;
    struct TreeNode **cur;
    int arr_idx = 0;
    int q_count = 512;
    int arr_count = 8;
    int tmp_count = 8;
    int idx = 0;


    arr = malloc(sizeof(int *) * arr_count);
    col_arr = malloc(sizeof(int) * arr_count);
    q = malloc(sizeof(struct TreeNode *) * q_count);
    new_q = malloc(sizeof(struct TreeNode *) * q_count);

    q[0] = root;
    q[1] = NULL;
    while(*q != NULL){
        cur =  q;
        memset(new_q, 0, sizeof(struct TreeNode *) * q_count);
        int *tmp = malloc(sizeof(int) * tmp_count);
        i = 0;
        j= 0;
        while(*cur != NULL) {
            if(i == tmp_count){
                tmp_count <<= 2;
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
            arr_count <<= 2;
            col_arr = realloc(col_arr, sizeof(int) * arr_count);
            arr = realloc(arr, sizeof(int *) * arr_count);
        }
        col_arr[idx] = i;
        arr[idx++] = tmp;

        memset(q, 0, sizeof(struct TreeNode *) * q_count);
        cur = new_q;
        new_q = q;
        q = cur;

    }

    *columnSizes = col_arr;
    *returnSize = idx;

    free(q);
    free(new_q);
    return arr;
}
