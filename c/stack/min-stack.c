typedef struct {
    int *st_data;
    int *st_min;
    int top_data;
    int top_min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->st_data = malloc(sizeof(int) * maxSize);
    stack->st_min = malloc(sizeof(int) * maxSize);
    stack->top_data = -1;
    stack->top_min = -1;
}

void minStackPush(MinStack *stack, int element) {
    stack->st_data[++stack->top_data] = element;

    if(stack->top_min == -1 || element <= stack->st_min[stack->top_min])
        stack->st_min[++stack->top_min] = element;
}

void minStackPop(MinStack *stack) {
    if(stack->top_min != -1 && stack->st_data[stack->top_data] ==
        stack->st_min[stack->top_min])
        --stack->top_min;

    --stack->top_data;
}

int minStackTop(MinStack *stack) {
    return stack->st_data[stack->top_data];
}

int minStackGetMin(MinStack *stack) {
    return stack->st_min[stack->top_min];
}

void minStackDestroy(MinStack *stack) {
    free(stack->st_data);
    free(stack->st_min);
}
