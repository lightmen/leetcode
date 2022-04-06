package containsduplicateii

func containsNearbyDuplicate(nums []int, k int) bool {
	flag := make(map[int]struct{}, k)
	l := 0
	r := 0
	for r < len(nums) {
		if _, ok := flag[nums[r]]; ok {
			return true
		}
		flag[nums[r]] = struct{}{}
		r++

		if r-l > k {
			delete(flag, nums[l])
			l++
		}
	}

	return false
}
