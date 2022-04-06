package sliding_window_maximum

func maxSlidingWindow(nums []int, k int) []int {
	arr := make([]int, 0)
	l := 0
	r := -1
	queue := make([]int, len(nums))
	front := 0
	end := -1
	for r < len(nums)-1 {
		r++
		for end-front >= 0 && nums[r] >= nums[queue[end]] {
			end--
		}
		end++
		queue[end] = r

		if r-l+1 > k {
			if queue[front] == l {
				front++
			}
			l++
		}

		if r-l+1 == k {
			arr = append(arr, nums[queue[front]])
		}
	}

	return arr
}
