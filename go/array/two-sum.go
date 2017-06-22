func twoSum(nums []int, target int) []int {
    var ret []int
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if ((nums[i] + nums[j]) == target) {
                ret = append(ret,i,j)
                return ret
            }
        }
    }

    return ret
}
