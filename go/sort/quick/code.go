package quick

import "math/rand"

func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func quickSort(arr []int) {
	quick(arr, 0, len(arr)-1)
}

func partiton(nums []int, start, end int) int {
	idx := rand.Intn(end-start+1) + start

	nums[idx], nums[start] = nums[start], nums[idx]
	target := nums[start]

	idx = start + 1
	for i := start + 1; i <= end; i++ {
		if nums[i] < target {
			nums[i], nums[idx] = nums[idx], nums[i]
			idx++
		}
	}
	idx--

	nums[start], nums[idx] = nums[idx], nums[start]
	return idx
}

func quick(arr []int, start, end int) {
	if end-start < 1 {
		return
	}

	idx := partiton(arr, start, end)
	quick(arr, start, idx-1)
	quick(arr, idx+1, end)
}
