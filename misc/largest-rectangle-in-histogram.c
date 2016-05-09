int largestRectangleArea(int* height, int heightSize) {
    int *stack;
    int top = -1;
    int i;
    int curh;
    int max = 0;

    stack = (int *)malloc(sizeof(int) * heightSize);

    for(i = 0; i <= heightSize; ++i){
        curh = (i == heightSize) ? -1 : height[i];
        while(top != -1 && curh <= height[stack[top]]){
            int  h = height[stack[top--]];
            int  w = ((top == -1) ? i : i - stack[top] - 1);

            if(h * w > max)
                max = h * w;
        }
        stack[++top] = i;
    }

    free(stack);
    return max;
}
