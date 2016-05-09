/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * Fill out 'n' to indicate how many elements return.
 */
int *rightSideView(struct TreeNode *root, int *n) {
    int order = 6;
    int *ret;
    struct TreeNode *queue[100],*tmp;
    int front,tail;
    int level = 0;
    int count;
    int i;
    
    *n = 0;
    ret = (int *)malloc(sizeof(int) * (1 << order));
    front = -1;
    tail = -1;
    
    if(root){
        tail++;
        queue[tail] = root;
        level = 1;
    }
    while(front != tail){
        i = 0;
        count = 0;
        while(i < level){
            i++;
            front = (front + 1) % 100;
            tmp = queue[front];
            ret[*n] = tmp->val;
            if(tmp->left){
                tail = (tail + 1) % 100;
                queue[tail] = tmp->left;
                count++;
            }
            if(tmp->right){
                tail = (tail + 1) % 100;
                queue[tail] = tmp->right;
                count++;
            }
        }
        level = count;
        (*n)++;
        if(*n == (1 << order)){
            order <<= 1;
            ret = realloc(ret,1 << order);
        }
    }
    return ret;
}
