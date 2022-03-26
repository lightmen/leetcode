package main

import (
	"math/rand"
	"time"
)

func partiton(nums []int, start, end int) int {
	idx := rand.Intn(end-start+1) + start
	nums[idx], nums[start] = nums[start], nums[idx]
	target := nums[start]

	idx = start + 1
	for i := idx; i <= end; i++ {
		if nums[i] < target {
			nums[i], nums[idx] = nums[idx], nums[i]
			idx++
		}
	}

	idx--
	nums[idx], nums[start] = nums[start], nums[idx]
	return idx
}

func quickSelect(nums []int, start, end, k int) int {
	idx := partiton(nums, start, end)
	if idx == k {
		return nums[idx]
	}

	if idx > k {
		return quickSelect(nums, start, idx, k)
	}

	return quickSelect(nums, idx+1, end, k)
}

func findKthLargest(nums []int, k int) int {
	rand.Seed(time.Now().UnixNano())
	return quickSelect(nums, 0, len(nums)-1, len(nums)-k)
}
