int maxArea(int* height, int heightSize) {
    int ret = 0;
    int start,end;
    int mul;
    int min;

    start = 1;
    end = heightSize;
    while(start < end){
        mul = end - start;
        if(height[start-1] < height[end-1]){
            min = height[start-1];
            ++start;
        }else{
            min = height[end-1];
            --end;
        }

        mul *= min;
        if(mul > ret)
            ret = mul;
    }

    return ret;
}
