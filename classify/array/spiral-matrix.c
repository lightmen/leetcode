/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int size = matrixRowSize * matrixColSize;
    int i,j,count;
    int *ret;
    int left,right,up,down;
    int direct = 0; //0  right,1 down, 2 left, 3 up

    ret = (int *)malloc(sizeof(int) * size);
    i = 0;
    j = 0;
    count = 0;
    left = 0;
    up = 0;
    right = matrixColSize - 1;
    down = matrixRowSize - 1;

    while(count < size){
        ret[count++] = matrix[i][j];
        switch(direct){
        case 0:
            if(j < right){
                ++j;
            }else{
                direct = (direct + 1) % 4;
                ++up;
                ++i;
            }
            break;
        case 1:
            if(i < down){
                ++i;
            }else{
                direct = (direct + 1) % 4;
                --right;
                --j;
            }
            break;
        case 2:
            if(j > left){
                --j;
            }else{
                direct = (direct + 1) % 4;
                --down;
                --i;
            }
            break;
        case 3:
            if(i > up){
                --i;
            }else{
                direct = (direct + 1) % 4;
                ++left;
                ++j;
            }
            break;
        }
    }

    return ret;
}
