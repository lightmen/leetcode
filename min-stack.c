typedef struct {
    int *data;
    int *min;
    int top_data;
    int top_min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->data = (int *)malloc(sizeof(int) * maxSize);
    stack->min = (int *)malloc(sizeof(int) * maxSize);
    
    stack->top_data = -1;
    stack->top_min = -1;
}

void minStackPush(MinStack *stack, int element) {
    stack->data[++stack->top_data] = element;
    
    if(stack->top_min == -1 || element <= stack->min[stack->top_min]){
        stack->min[++stack->top_min] = element;
    }
}

void minStackPop(MinStack *stack) {
    int top = minStackTop(stack);

    if(top <= minStackGetMin(stack))
        stack->top_min--;

    stack->top_data--;
}

int minStackTop(MinStack *stack) {
    return stack->data[stack->top_data];
}

int minStackGetMin(MinStack *stack) {
    return stack->min[stack->top_min];
}

void minStackDestroy(MinStack *stack) {
    /* we can't call the free() to free stack->data and
	 * stack->min, or the runtime error will happen 
	*/
}
