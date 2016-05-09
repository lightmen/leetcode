int maxArea(int* height, int heightSize) {
    int i,j;
    int area = INT_MIN;
    int min_height;
    int tmp;
    
    i = 0;
    j = heightSize - 1;
    while(i < j){
        min_height = height[i] < height[j] ? height[i] : height[j];
        tmp = min_height * (j - i);
        if( tmp > area)
            area = tmp;

        if(height[i] > height[j])
            j--;
        else
            i++;
    }
    
    return area;
}
