func containsNearbyDuplicate(nums []int, k int) bool {
    var mp map[int]int
    mp = make(map[int]int)

    for idx, value := range nums {
        key, ok := mp[value]
        if(ok && idx - key <= k){
            return true
        }
        mp[value] = idx
    }

    return false
}
