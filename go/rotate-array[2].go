func rotate(nums []int, k int)  {
    k %= len(nums)

    reverse(nums, 0, len(nums) - k - 1)
    reverse(nums, len(nums) - k, len(nums) - 1)
    reverse(nums, 0, len(nums) - 1)
}

func reverse(nums []int, start, end int){
    for(start < end){
        nums[start], nums[end] = nums[end], nums[start]
        start++
        end--
    }
}
