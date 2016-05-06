typedef struct {
    int *q1;
    int *q2;
    int f1;
    int e1;
    int f2;
    int e2;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->q1 = malloc(sizeof(int) * maxSize);
    stack->q2 = malloc(sizeof(int) * maxSize);
    stack->f1 = 0;
    stack->e1 = 0;
    stack->f2 = 0;
    stack->e2 = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    if(stack->f1 == stack->e1){
        stack->q1[stack->e1++] = element;
        while(stack->f2 != stack->e2){
            int value = stack->q2[stack->f2++];
            stack->q1[stack->e1++] = value;
        }
        stack->f2= stack->e2 = 0;
    }else{
        stack->q2[stack->e2++] = element;
        while(stack->f1 != stack->e1){
            int value = stack->q1[stack->f1++];
            stack->q2[stack->e2++] = value;
        }
        stack->f1 = stack->e1 = 0;
    }
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    if(stack->f1 != stack->e1)
        stack->f1++;
    else
        stack->f2++;
}

/* Get the top element */
int stackTop(Stack *stack) {
    if(stack->f1 != stack->e1)
        return stack->q1[stack->f1];
    else
        return stack->q2[stack->f2];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->f1 == stack->e1 && stack->f2 == stack->e2;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->q1);
    free(stack->q2);
}
