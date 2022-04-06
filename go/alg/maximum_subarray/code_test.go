package maximumsubarray

import "testing"

func TestMaxSubArray(t *testing.T) {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	if maxSubArray(nums) != 6 {
		t.Fatalf("test failed")
	}
}
