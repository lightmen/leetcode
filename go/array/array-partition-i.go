func arrayPairSum(nums []int) int {
    sort.Ints(nums)

    ret := 0
    for i := 0; i < len(nums); i += 2 {
        ret += nums[i]
    }

    return ret
}
