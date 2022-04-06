package searchinrotatedsortedarray

func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	for l <= r {
		mid := l + (r-l)/2
		if nums[mid] == target {
			return mid
		}

		if nums[mid] > target {
			if nums[l] <= target || nums[l] > nums[mid] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		} else {
			if nums[r] >= target || nums[r] < nums[mid] {
				l = mid + 1
			} else {
				r = mid - 1
			}

		}
	}

	return -1
}
