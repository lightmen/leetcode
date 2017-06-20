func searchInsert(nums []int, target int) int {
    i := 0
    j := len(nums) - 1
    for i <= j {
        mid := (i + j) >> 1
        if nums[mid] == target {
            return mid
        }else if nums[mid] > target {
            j = mid - 1
        }else {
            i = mid + 1
        }
    }

    return i
}
