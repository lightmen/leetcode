void reverse(int *nums, int start, int end)
{
    while(start < end){
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        ++start;
        --end;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int index = -1;
    int i;

    for(i = numsSize - 2; i >= 0; --i){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(nums,0,numsSize - 1);
        return ;
    }

    for(i = numsSize - 1; i > index; --i){
        if(nums[i] > nums[index]){
            int tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            break;
        }
    }

    reverse(nums,index+1,numsSize - 1);
}
