func removeDuplicates(nums []int) int {
    i, j := 0, 0
    for j < len(nums) {
        for j < len(nums) && nums[i] == nums[j] {
            j++
        }
        if j < len(nums) {
            i++
            nums[i], nums[j] = nums[j], nums[i]
        }
        j++
    }

    return i + 1
}
