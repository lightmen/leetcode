void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortColors(int* nums, int numsSize) {
    int i,left,right;

    i = 0;
    left = 0;
    right = numsSize - 1;
    while(i <= right){
        if(nums[i] == 0){
            swap(&nums[left],&nums[i]);
            left++;
            i++;
        }else if(nums[i] == 1){
            i++;
        }else{
            swap(&nums[right],&nums[i]);
            right--;
        }
    }
}
