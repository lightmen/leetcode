int get_maxarea(int *height, int size)
{
    int *stack;
    int top = -1;
    int i;
    int cur;
    int ret = 0;

    stack = (int *)malloc(sizeof(int) * size);

    for(i = 0; i <= size; ++i){
        cur = i == size ? -1 : height[i];
        while(top != -1 && cur <= height[stack[top]]){
            int h = height[stack[top--]];
            int w = top == -1 ? i : i - stack[top] - 1;

            if(h * w > ret)
                ret = h * w;
        }
        stack[++top] = i;
    }

    free(stack);
    return ret;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int *height;
    int i,j;
    int max_area = 0;
    int area;

    height = (int *)malloc(sizeof(int) * matrixColSize);
    memset(height,0,sizeof(int) * matrixColSize);

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(matrix[i][j] == '0')
                height[j] = 0;
            else
                height[j]++;
        }

        area = get_maxarea(height,matrixColSize);

        if(area > max_area)
            max_area = area;
    }

    free(height);
    return max_area;
}
