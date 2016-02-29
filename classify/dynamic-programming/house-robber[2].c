int rob(int* nums, int numsSize) {
    int value,pre_value,tmp;
    int i;

    pre_value = 0;
    value = 0;

    for(i = 0; i < numsSize; ++i){
        tmp = value;
        value = pre_value + nums[i] > value ? pre_value + nums[i] : value;
        pre_value = tmp;
    }

    return value;
}
