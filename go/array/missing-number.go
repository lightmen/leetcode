func missingNumber(nums []int) int {
    ret := len(nums) * (len(nums) + 1) / 2
    for _, v := range nums {
        ret -= v
    }

    return ret
}
