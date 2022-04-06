package shortestunsortedcontinuoussubarray

func findUnsortedSubarray(nums []int) int {
	st := make([]int, len(nums))
	top := -1

	left := len(nums)

	for idx, val := range nums {
		for top > -1 && val < nums[st[top]] {
			if st[top] < left {
				left = st[top]
			}
			top--
		}
		top++
		st[top] = idx
	}

	right := -1
	top = -1

	for idx := len(nums) - 1; idx >= 0; idx-- {
		for top > -1 && nums[idx] > nums[st[top]] {
			if st[top] > right {
				right = st[top]
			}
			top--
		}
		top++
		st[top] = idx
	}

	if right == -1 {
		return 0
	}

	return right - left + 1
}
