func containsNearbyDuplicate(nums []int, k int) bool {
    var mp map[int]int
    mp = make(map[int]int)

    for i := 0; i < len(nums); i++ {
        idx, ok := mp[nums[i]]
        if(ok && i - idx <= k){
            return true
        }else {
            mp[nums[i]] = i
        }
    }

    return false
}
