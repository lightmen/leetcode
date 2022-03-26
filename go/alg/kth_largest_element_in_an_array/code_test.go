package main

import "testing"

func TestFindKthLargest(t *testing.T) {
	// nums := []int{3, 2, 1, 5, 6, 4}
	// k := 2
	// val := findKthLargest(nums, k)
	// t.Logf("%d", val) //5

	nums := []int{3, 1, 2, 4}
	k := 2
	val := findKthLargest(nums, k)
	t.Logf("%d", val) //3

	// nums := []int{3, 2, 3, 1, 2, 4, 5, 5, 6}
	// k := 4
	// val := findKthLargest(nums, k)
	// t.Logf("%d", val) //4
}
