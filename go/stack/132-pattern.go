package stack

func find132pattern(nums []int) bool {
	for i := 2; i < len(nums); i++ {
		status := 0
		for j := i -1; j >= 0; j-- {
			if status == 0 && nums[j] > nums[i] {
				status = 1
				continue
			}

			if status == 1 && nums[j] < nums[i] {
				return true
			}
		}
	}

	return false
}
