package sliding_window_maximum

import (
	"reflect"
	"testing"
)

func TestMaxSlidingWindow(t *testing.T) {
	nums := []int{1,3,-1,-3,5,3,6,7}
	k := 3
	expect := []int{3,3,5,5,6,7}
	result := maxSlidingWindow(nums, k)
	if !reflect.DeepEqual(expect, result) {
		t.Fatalf("test failed: %v", result)
	}

	nums = []int{1}
	k = 1
	expect = []int{1}
	result = maxSlidingWindow(nums, k)
	if !reflect.DeepEqual(expect, result) {
		t.Fatalf("test failed: %v", result)
	}

	nums = []int{1, -1}
	k = 1
	expect = []int{1, -1}
	result = maxSlidingWindow(nums, k)
	if !reflect.DeepEqual(expect, result) {
		t.Fatalf("test failed: %v", result)
	}
}
