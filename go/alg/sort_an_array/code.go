package sortanarray

import "math/rand"

func quitSort(nums []int, start, end int) {
	if start >= end {
		return
	}

	idx := rand.Intn(end-start+1) + start
	nums[idx], nums[start] = nums[start], nums[idx]

	idx = start + 1
	for i := start + 1; i <= end; i++ {
		if nums[i] < nums[start] {
			nums[idx], nums[i] = nums[i], nums[idx]
			idx++
		}
	}
	idx--
	if nums[start] > nums[idx] {
		nums[start], nums[idx] = nums[idx], nums[start]
	}

	quitSort(nums, start, idx-1)
	quitSort(nums, idx+1, end)

	return
}
func sortArray(nums []int) []int {
	quitSort(nums, 0, len(nums)-1)
	return nums
}
