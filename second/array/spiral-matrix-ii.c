/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **ret;
    int i,j;
    int left,right,up,down;
    int direct = 0;
    int size = n * n;
    int cur = 1;

    ret = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; ++i)
        ret[i] = (int *)malloc(sizeof(int) * n);

    left = 0;
    up = 0;
    down = n - 1;
    right = n - 1;

    i = 0;
    j = 0;
    while(cur <= size){
        ret[i][j] = cur++;
        switch(direct){
        case 0: // left to right
            if(j < right){
                j++;
            }else{
                direct = (direct + 1) % 4;
                up++;
                i++;
            }
            break;
        case 1: // up to down
            if(i < down){
                i++;
            }else{
                direct = (direct + 1) % 4;
                right--;
                j--;
            }
            break;
        case 2: // right to left
            if(j > left){
                --j;
            }else{
                direct = (direct + 1) % 4;
                down--;
                i--;
            }
            break;
        case 3: // down to up
            if(i > up){
                i--;
            }else{
                direct = (direct + 1) % 4;
                left++;
                j++;
            }
        }
    }

    return ret;
}
