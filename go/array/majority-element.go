func majorityElement(nums []int) int {
    var count, value int

    for i := range nums {
        if count == 0 {
            value = nums[i]
        }
        if value == nums[i] {
            count++
        }else{
            count--
        }
    }

    return value
}
