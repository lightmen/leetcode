int *stack;

int maxArea(int *height, int col)
{
    int top;
    int i;
    int max_area,cur;

    max_area = 0;
    top = -1;
    i = 0;
    for(i = 0; i <= col; ++i){
        cur = i == col ? -1 : height[i];
        while(top != -1 && cur <= height[stack[top]]){
            int h = height[stack[top--]];
            int w = top == -1 ? i : i - stack[top] - 1;

            if(h * w > max_area)
                max_area = h * w;
        }

        stack[++top] = i;
    }

    return max_area;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int *height;
    int i, j, area, max_area;

    height = (int *)malloc(sizeof(int) * matrixColSize);
    stack = (int *)malloc(sizeof(int) * matrixColSize);
    memset(height, 0,sizeof(int) * matrixColSize);

    max_area = 0;
    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(matrix[i][j] == '0')
                height[j] = 0;
            else
                height[j]++;
        }

        area = maxArea(height,matrixColSize);

        if(area > max_area)
            max_area = area;
    }

    free(stack);
    free(height);

    return max_area;
}
