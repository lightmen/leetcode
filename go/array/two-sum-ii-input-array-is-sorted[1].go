func twoSum(numbers []int, target int) []int {
    var mp = make(map[int] int)

    for key, value := range numbers {
        idx, ok := mp[target - value]
        if ok {
            return []int{idx + 1, key + 1}
        }

        mp[value] = key
    }

    return []int{-1,-1}
}
