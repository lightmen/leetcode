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

    struct TreeLinkNode **arr = malloc(sizeof(struct TreeLinkNode *) * 5000);
    struct TreeLinkNode **next_arr = malloc(sizeof(struct TreeLinkNode *) * 5000);
    int top;
    int next_top;

    top = -1;
    arr[++top] = root;

    while(top > -1){
        next_top = -1;
        for(int i = 0; i <= top; ++i){
            arr[i]->next = (i != top) ? arr[i+1] : NULL;
            if(arr[i]->left)
                next_arr[++next_top] = arr[i]->left;
            if(arr[i]->right)
                next_arr[++next_top] = arr[i]->right;
        }

        struct TreeLinkNode **tmp = arr;
        arr = next_arr;
        next_arr = tmp;
        top = next_top;
    }

    free(arr);
    free(next_arr);
}
