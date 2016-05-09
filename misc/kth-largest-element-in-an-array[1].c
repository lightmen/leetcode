#define _cmp(a,b) ((a) > (b))
int findKthLargest(int* nums, int numsSize, int k) {
    int start,end,tmp;
    int i,j;
    int value;
    start = 0;
    end = numsSize - 1;
    k--;
    while(start < end){
        i = start - 1;
        j = end + 1;
        value = nums[(i+j) >> 1];
        while(i < j){
            for(--j; _cmp(value,nums[j]); --j) ;
            
            for(++i; _cmp(nums[i],value); ++i) ;

            if(i < j){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        if(k > j)
            start = j + 1;
        else
            end = j;
    }
    
    return nums[k];
}
