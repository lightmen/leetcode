int largestRectangleArea(int* heights, int heightsSize) {
    int *st;
    int top = -1;
    int maxArea = 0;
    int i;

    st = malloc(sizeof(int) * heightsSize);
    for(i = 0; i <= heightsSize; ++i){
        int curh = ((i == heightsSize) ? 0 : heights[i]);
        while(top > -1 && curh <= heights[st[top]]){
            int h = heights[st[top--]];
            int w = ((top == -1) ? i : (i - st[top] - 1));

            if(h * w > maxArea)
                maxArea = h * w;
        }

        st[++top] = i;
    }

    free(st);
    return maxArea;
}
