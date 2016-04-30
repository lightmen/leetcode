#define min(a,b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int start,end;
    int ret = 0;
    int mul;

    start = 0;
    end = heightSize - 1;
    while(start < end){
        mul = min(height[start],height[end]) * (end - start);
        if(mul > ret)
            ret = mul;
        if(height[start] > height[end])
            --end;
        else
            ++start;
    }

    return ret;
}
