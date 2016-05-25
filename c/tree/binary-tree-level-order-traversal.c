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
    int idx = 0;
    int alloc_count = 1024;

    arr = malloc(sizeof(int *) * alloc_count);
    col_arr = malloc(sizeof(int) * alloc_count);
    q = malloc(sizeof(struct TreeNode *) * alloc_count);
    new_q = malloc(sizeof(struct TreeNode *) * alloc_count);

    q[0] = root;
    q[1] = NULL;
    while(*q != NULL){
        cur =  q;
        memset(new_q, 0, sizeof(struct TreeNode *) * alloc_count);
        int *tmp = malloc(sizeof(int) * alloc_count);
        i = 0;
        j= 0;
        while(*cur != NULL) {
            tmp[i++] = (*cur)->val;
            if((*cur)->left)
               new_q[j++] = (*cur)->left;
            if((*cur)->right)
                new_q[j++] = (*cur)->right;
            cur++;
        }
        col_arr[idx] = i;
        arr[idx++] = tmp;

        memset(q, 0, sizeof(struct TreeNode *) * alloc_count);
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
