typedef struct {
    int *queue1;
    int f1,e1;
    int *queue2;
    int f2,e2;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->queue1 = (int *)malloc(sizeof(int) * maxSize);
    stack->queue2 = (int *)malloc(sizeof(int) * maxSize);
    stack->f1 = 0;
    stack->e1 = 0;
    stack->f2 = 0;
    stack->e2 = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    stack->queue1[stack->e1++] = element;
}


/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    while(stack->e1 - stack->f1 > 1){
        stack->queue2[stack->e2++] = stack->queue1[stack->f1++];
    }

    int *tmp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = tmp;
    stack->f1 = stack->f2;
    stack->e1 = stack->e2;
    stack->f2 = 0;
    stack->e2 = 0;
}

/* Get the top element */
int stackTop(Stack *stack) {
    while(stack->e1 - stack->f1 > 1){
        stack->queue2[stack->e2++] = stack->queue1[stack->f1++];
    }

    int *tmp = stack->queue1;
    int ret = stack->queue1[stack->f1];
    stack->queue2[stack->e2++] = stack->queue1[stack->f1++];
    stack->queue1 = stack->queue2;
    stack->queue2 = tmp;
    stack->f1 = stack->f2;
    stack->e1 = stack->e2;
    stack->f2 = 0;
    stack->e2 = 0;

    return ret;
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->f1 == stack->e1;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    if(stack == NULL)
        return ;

    free(stack->queue1);
    free(stack->queue2);
}
