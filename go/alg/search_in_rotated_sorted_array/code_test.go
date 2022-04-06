package searchinrotatedsortedarray

import "testing"

func TestSearch(t *testing.T) {
	nums := []int{4, 5, 6, 7, 8, 1, 2, 3}
	target := 8
	if search(nums, target) != 4 {
		t.Fatal("test failed")
	}

	nums = []int{1, 2, 3, 4}
	target = 3
	if search(nums, target) != 2 {
		t.Fatal("test failed")
	}
}
