package stack

func mostCompetitive(nums []int, k int) []int {
	st := make([]int, len(nums))
	top := -1

	for i := 0; i < len(nums); i++ {
		val := nums[i]
		for top > -1 && val < st[top] &&(top + len(nums) - i) >= k {
			top--
		}

		top++
		st[top] = val
	}

	return st[:k]
}