int majorityElement(int* nums, int numsSize) {
    int count,value,i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(count == 0){
            ++count;
            value = nums[i];
        }else if(value == nums[i]){
            ++count;
        }else{
            --count;
        }
    }

    return value;
}
