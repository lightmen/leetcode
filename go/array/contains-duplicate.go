func containsDuplicate(nums []int) bool {
    var mp = make(map[int]int)

    for idx, value := range nums {
        _, ok := mp[value]
        if ok {
            return true
        }
        mp[value] = idx
    }

    return false
}
