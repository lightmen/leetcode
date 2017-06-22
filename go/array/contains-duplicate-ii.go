func containsNearbyDuplicate(nums []int, k int) bool {
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums) && j <= i + k; j++{
            if(nums[i] == nums[j]){
                return true
            }
        }
    }

    return false
}
