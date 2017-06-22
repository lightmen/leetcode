func rotate(nums []int, k int)  {
    k %= len(nums)
    r := make([]int, len(nums))
    copy(r, nums[len(nums) - k:])
    copy(r[k:], nums[:len(nums) - k])
    copy(nums, r)
}
