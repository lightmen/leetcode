int trap(int* height, int heightSize) {
    int i,j,k;
    int ret = 0,sub = 0;
    int cur_height = 1;
    int start,end;

    start = 0;
    end = heightSize - 1;
    while(start < heightSize && !height[start])
        ++start;
    while(end >= 0 && !height[end])
        --end;

    i = start;
    j = end;
    while(i < j){
        while(i < j && height[i] < cur_height)
            ++i;
        while(j > i && height[j] < cur_height)
            --j;
        if(i + 1 >= j)
            break;

        ret += (j - i + 1);
        cur_height++;
    }
    
    cur_height--;
    for(i = start; i <= end; ++i)
        sub += height[i] > cur_height ? cur_height : height[i];
    
    ret -= sub;
    return ret;
}
