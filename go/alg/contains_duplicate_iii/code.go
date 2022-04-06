package containsduplicateiii

func abs(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

func getKey(val, cnt int) int {
	key := val / (cnt + 1)
	if val < 0 {
		key--
	}

	return key
}

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	bucket := make(map[int]int, k)

	for idx, val := range nums {
		key := getKey(val, t)

		if _, ok := bucket[key]; ok {
			return true
		}

		if _, ok := bucket[key-1]; ok && abs(bucket[key-1], val) <= t {
			return true
		}

		if _, ok := bucket[key+1]; ok && abs(bucket[key+1], val) <= t {
			return true
		}

		bucket[key] = val
		if idx >= k {
			delete(bucket, getKey(nums[idx-k], t))
		}
	}

	return false
}
