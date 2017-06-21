func removeElement(nums []int, val int) int {
    i := 0
    j := len(nums) - 1
    for i <= j {
        for i <= j && nums[i] != val {
            i++
        }

        for j >= i && nums[j] == val {
            j--
        }

        if(i < j) {
            nums[i], nums[j] = nums[j], nums[i]
        }
    }

    return i
}
