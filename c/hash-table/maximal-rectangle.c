int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int max_area = 0;
    int h,w;
    int *height;
    int *st;
    int i,j;
    int top;

    height = malloc(sizeof(int) * (matrixColSize + 1));
    st = malloc(sizeof(int) * (matrixColSize + 1));
    memset(height, 0, sizeof(int) * (matrixColSize + 1));

    for(i = 0; i < matrixRowSize; ++i){
        top = -1;
        for(j = 0; j <= matrixColSize; ++j){
            if(j < matrixColSize)
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;

            while(top > -1 && height[j] <= height[st[top]]){
                h = height[st[top--]];
                w = ((top == -1) ? j : (j - st[top] - 1));

                if(h * w > max_area)
                    max_area = h * w;
            }

            st[++top] = j;
        }
    }

    free(height);
    free(st);

    return max_area;
}
