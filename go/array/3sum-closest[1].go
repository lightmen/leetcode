func abs(x int) int {
    if x < 0 {
        return -x
    }

    return x
}

func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    ret := nums[0] + nums[1] + nums[2]
    for i := 0; i < len(nums) - 2; i += 1 {
        start := i + 1
        end := len(nums) - 1
        for start < end {
            sum :=  nums[i] + nums[start] + nums[end]
            if abs(sum - target) < abs(ret - target) {
                ret = sum
            }else if sum > target {
                end -= 1
            }else {
                start += 1
            }
        }
    }

    return ret
}
