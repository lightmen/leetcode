package sliding_window_maximum

func maxSlidingWindow(nums []int, k int) []int {
	if k > len(nums) {
		k = len(nums)
	}

	qArr := make([]int, len(nums))
	l := 0
	r := -1

	arr := make([]int, 0, len(nums) - k + 1)
	for idx, val := range  nums {
		for l <= r && idx - qArr[l] >= k {
			l++
		}

		for r >= l && nums[qArr[r]] <= val {
			r--
		}

		r++
		qArr[r] = idx

		if idx >= k-1 {
			arr = append(arr, nums[qArr[l]])
		}
	}

	return arr
}
