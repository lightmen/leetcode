int majorityElement(int* nums, int numsSize) {
    int count,value,i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(count == 0 || nums[i] == value){
            ++count;
            value = nums[i];
        }else{
            --count;
        }
    }

    return value;
}
