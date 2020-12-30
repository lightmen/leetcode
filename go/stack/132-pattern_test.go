package stack

import "testing"

func TestFind132pattern(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	if find132pattern(nums) == true {
		t.Fatalf("test failed")
	}

	nums = []int{1,0,1,-4,-3}
	if find132pattern(nums) == true {
		t.Fatalf("test failed")
	}

	nums = []int{3, 1, 4, 2}
	if find132pattern(nums) == false {
		t.Fatalf("test failed")
	}

	nums = []int{-1, 3, 2, 0}
	if find132pattern(nums) == false {
		t.Fatalf("test failed")
	}
}
