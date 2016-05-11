int trap(int* height, int heightSize) {
    int max_height = 0;
    int max_index = 0;
    int i;
    int ret = 0;

    for(i = 0; i < heightSize; ++i){
        if(height[i] > max_height){
            max_height = height[i];
            max_index = i;
        }
    }

    max_height = 0;
    for(i = 0; i < max_index; ++i){
        if(max_height > height[i])
            ret += (max_height - height[i]);
        else
            max_height = height[i];
    }

    max_height = 0;
    for(i = heightSize - 1; i > max_index; --i){
        if(max_height > height[i])
            ret += (max_height - height[i]);
        else
            max_height = height[i];
    }

    return ret;
}
