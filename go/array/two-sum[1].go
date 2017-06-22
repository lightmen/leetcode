two-sum
func twoSum(nums []int, target int) []int {
    var mp = make(map[int] int)
    for i := 0; i < len(nums); i++ {
        mp[nums[i]] = i
    }

    for j := 0; j < len(nums); j++{
        index, ok := mp[target - nums[j]]
        if(ok && index != j){
            return []int{index,j}
        }
    }

    return nil
}
