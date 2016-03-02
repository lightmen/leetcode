int max_2(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    int value,pre_value;
    int i,tmp;
    int val0;

   pre_value = 0;
   value = nums[0];
    for(i = 2; i < numsSize; ++i){
        tmp = value;
        value = max_2(value,pre_value + nums[i-1]);
        pre_value = tmp;
    }

    val0 = value;

    pre_value = 0;
    value = 0;
    for(i = 2; i <= numsSize; ++i){
        tmp = value;
        value = max_2(value, pre_value + nums[i-1]);
        pre_value = tmp;
    }


    return max_2(value,val0);
}
