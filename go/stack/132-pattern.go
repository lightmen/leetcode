package stack

func find132pattern(nums []int) bool {
	if len(nums) < 3 {
		return false
	}

	min := make([]int, len(nums))
	min[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		min[i] = min[i-1]
		if nums[i] < min[i] {
			min[i] = nums[i]
		}
	}

	st := make([]int, len(nums))
	top := -1

	for j := len(nums) -1; j >= 0; j-- {
		if nums[j] <= min[j] {
			continue
		}

		for top > -1 && min[j] >= st[top] {
			top--
		}

		if top > -1 && nums[j] > st[top] {
			return true
		}

		top++
		st[top] = nums[j]
	}

	return false
}
