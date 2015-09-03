int maxArea(int* height, int heightSize) {
    int ret = 0;
    int start,end;
    int mul;

    start = 0;
    end = heightSize-1;
    while(start < end){
        if(height[start] < height[end]){
            mul = height[start] * (end - start);
            ++start;
        }else{
            mul = height[end] * (end - start);
            --end;
        }

        ret = mul > ret ? mul : ret;
    }

    return ret;
}
