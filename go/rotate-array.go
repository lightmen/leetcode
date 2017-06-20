func rotate(nums []int, k int)  {
    k = k % len(nums)

    for k > 0 {
        var tmp = nums[len(nums) - 1]
        for i := len(nums) - 1; i > 0; i-- {
            nums[i] = nums[i - 1]
        }
        nums[0] = tmp
        k--
    }
}
