/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode *stack[1000];
    int top;
    struct TreeNode *cur;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *bit = (struct BSTIterator *)malloc(sizeof(struct BSTIterator));

    bit->top = 0;
    bit->cur = root;

    return bit;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    if(iter->cur != NULL || iter->top > 0)
        return true;

    return false;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    int ret;
    while(iter->cur){
        iter->stack[iter->top++] = iter->cur;
        iter->cur = iter->cur->left;
    }

    iter->cur = iter->stack[--iter->top];
    ret = iter->cur->val;
    iter->cur = iter->cur->right;
    return ret;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {

}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
