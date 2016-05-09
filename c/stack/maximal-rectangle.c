int *st;

int maxArea(int *heights, int matrixColSize)
{
    int top = -1;
    int i;
    int area = 0;

    for(i = 0; i <= matrixColSize; ++i){
        while(top != -1 && heights[i] <= heights[st[top]]){
            int h = heights[st[top--]];
            int w = ((top == -1) ? i : (i - st[top] - 1));

            if(h * w > area)
                area = h * w;
        }
        st[++top] = i;
    }

    return area;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int *heights;
    int i,j;
    int max_area = 0;
    int area = 0;

    heights = malloc(sizeof(int) * (matrixColSize+1));
    memset(heights, 0, sizeof(int) * (matrixColSize+1));
    st = malloc(sizeof(int) * (matrixColSize+1));

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j]++;
        }

        area = maxArea(heights,matrixColSize);
        max_area = area > max_area ? area : max_area;
    }

    free(heights);
    free(st);

    return max_area;
}
