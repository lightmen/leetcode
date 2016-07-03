/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL)
        return ;

    int arr_size = 64;
    int next_size = 64;
    struct TreeLinkNode **arr = malloc(sizeof(struct TreeLinkNode *) * arr_size);
    struct TreeLinkNode **next_arr = malloc(sizeof(struct TreeLinkNode *) * next_size);
    int top;
    int next_top;

    top = -1;
    arr[++top] = root;

    while(top > -1){
        next_top = -1;
        for(int i = 0; i <= top; ++i){
            arr[i]->next = (i != top) ? arr[i+1] : NULL;
            if(next_top + 2 >= arr_size){
                arr_size <<= 1;
                next_arr = realloc(next_arr, sizeof(struct TreeLinkNode *) * arr_size);
            }
            if(arr[i]->left)
                next_arr[++next_top] = arr[i]->left;
            if(arr[i]->right)
                next_arr[++next_top] = arr[i]->right;
        }

        struct TreeLinkNode **tmp = arr;
        arr = next_arr;
        next_arr = tmp;
        top = next_top;

        int size = arr_size;
        arr_size = next_size;
        next_size = size;
    }

    free(arr);
    free(next_arr);
}
