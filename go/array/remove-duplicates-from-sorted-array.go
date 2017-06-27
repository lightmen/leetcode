func removeDuplicates(nums []int) int {
    c := 0

    if len(nums) == 0 {
        return 0
    }

    for i := 0; i < len(nums); i++ {
        if(nums[i] != nums[c]){
            c++
            nums[c], nums[i] = nums[i], nums[c]
        }
    }

    return c + 1
}
